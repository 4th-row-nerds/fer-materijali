[← Natrag](..)

# Web Sigurnost - 2. dio

## Umetanje naredbi OS-a

```php
system("grep -r" . $_GET["arg"]);
```

napadač može postaviti `arg` na `; rm -rf /var/www/html` i zbog vulnerabilnosti u sustavu, pokreće se `grep -r ; rm -rf /var/www/html`

[Vježbanje zadataka na hackultet platformi](platforma.hackultet.hr)

[Resursi](https://gtfobins.github.io/) za vježbanje ubacivanja argumenata


## Directory traversal

Neke aplikacije dohvaćaju datoteke ovisno o korisničkom unosu
```php
file_get_contents("/var/www/html/files/".$_GET["filename"]);
```
- Na Linuxu i Windowsu ".." znači "idi direktorij nazad"
- Ako je filename postavljen na `../../../../../../../../../etc/passwd`
  - `/var/www/html/../../../../../../../../../etc/passwd` -> /etc/passwd
  - Višak "../" ne smeta
- Što pokušati čitati:
  - U CTF-ovima – flag, ako znamo gdje je
  - U stvarnom svijetu (ponekad i u CTF-ovima) – konfiguracijske datoteke koje sadrže lozinke, izvorni kod i slično

### Directory traversal - primjer
- http://chal.platforma.hacknite.hr:11008/ - znamo gdje su zapisane lozinke
- http://chal.platforma.hacknite.hr:12004/ - Zadatak "Hosting" – malo teže
- http://chal.platforma.hacknite.hr:13004/index.php - Zadatak "putovanje kroz direktorije" – ima filter (source kod

[CISA - directory traversal](https://www.cisa.gov/known-exploited-vulnerabilities-catalog?search_api_fulltext=directory+traversal) – directory traversal ranjivosti u softveru za koje se zna da su ih iskoristili/pokušali iskoristiti stvarni napadači protiv stvarnih meta


## File upload

- Nije sigurno provjeravanje u javascriptu jer se lagano zaobiđe.

- Ponekad se provjerava „magic number” – lako se izmijeni

- Ponekad se na backendu izričito zabrani upload „opasnih” ekstenzija kao što su php

- Ali često postoje alternativne ekstenzije koje su isto izvršne – npr. .phtml, .php5 i slično

- Na Apache serveru - .htaccess datotekom se mogu odrediti ekstenzije – ako se može uploadati naš .htaccess možemo postaviti bilo koju ekstenziju kao izvršnu

- Upload SVG datoteke -> XSS!

- Arbitrary file write (ako kontroliramo i lokaciju gdje se datoteka zapisuje)

- Zapisati SSH ključeve u authorized_keys

- Zapisati cronjob ili overwriteati neku shell skriptu koja će se nekad pokrenuti

- [Python aplikacije](https://www.sonarsource.com/blog/pretalx-vulnerabilities-how-to-get-accepted-at-every-conference/) - mora moći zapisati .pth datoteku u direktorij `~/.local/lib/pythonX.Y/site-packages`

- [NodeJS aplikacije](https://www.sonarsource.com/blog/why-code-security-matters-even-in-hardened-environments/) - pisanje po proc filesystemu – efektivno memory corruption

- NTFS – zloupotreba alternate data streamova ("[evil colon napadi](https://www.helpnetsecurity.com/2022/09/22/evil-colon-attacks/)")

- Naknadne ranjivosti pri procesiranju datoteka – npr. exiftool CVE-2021-22204

- Distribucija malwarea, prepunjavanje diska itd.

### File upload - primjeri
- http://chal.platforma.hacknite.hr:10016/
- Validacija ekstenzije – klijentska strana
- Preimenuj shell u „shell.jpg” -> burp intercept -> preimenuj natrag u „.php” -> shell!
- http://chal.platforma.hacknite.hr:11013/ - više restrikcija
  - Dodamo na početak filea `GIF89A` i server misli da je gif
  - Koristimo alternativnu ekstenziju `phtml`


## Server-side template injection

Predlošci (engl. templates) – tehnologija za dinamičko generiranje HTML-a koja se koristi s nekim web frameworcima (npr. Jinja2 uz Flask)
  - Statički sadržaj + dinamičke varijable
  - npr. `<b> Pozdrav {{korisnik.ime}} ! </b>`
  - Često (ali ne uvijek) i automatski ugrađen XSS filter
  - Ako korisnici kontroliraju samo vrijednosti varijabli (`korisnik.ime`) to
    generalno nije problem

Problem je ako kontroliraju sadržaj predloška

### Predlošci – češći problem u stvarnom svijetu

- Imamo predložak: `<p id={{query}}>abc</p>`
- Template engine uglavnom obavlja XSS filtering ali nije svemoguć
- Ako korisnik kontrolira sadržaj varijable query i postavi ju na
```js
foo onmouseover=alert(1)
```
generirat će se HTML:
```html
<p id=foo onmouseover=alert(1)>abc</p>
```
imamo XSS sa `onmouseover=alert(1)`
- Ispravak – uvijek stavljati varijable pod navodnike

## XXE injekcija

- XXE (XML external entity) – značajka XML-a koja se može koristiti za dohvat sadržaja datoteka
- Nije namijenjena da se koristi s unosom koji bi mogao doći od napadača

Zadatak – shopping košarica - http://chal.platforma.hacknite.hr:12002/

## Nesigurna deserijalizacija
Serijalizacija je proces pretvaranja složenijih tipova podataka u jednostavniji oblik. Svrha je pohraniti podatke u obliku u kojem se oni mogu zapisati u datoteku, slati mrežom ili pohraniti u bazu podataka. - Deserijalizacija je obrnuti proces

- Nesigurna deserijalizacija – deserijalizacija podataka koje kontrolira korisnik, tako da korisnik može stvoriti proizvoljne objekte u aplikaciji – to često može dovesti do izvršavanja koda
- Python – pickle deserijalizacija – deserijalizirati se mogu proizvoljne klase, čak i one koje napadač sam napiše
- Kod ostalih jezika, napadač je uglavnom ograničen na one klase koje već postoje u aplikaciji

### Nesigurna deserijalizacija - primjeri
"Autentifikacija bez lozinke" - http://chal.platforma.hacknite.hr:10014/index.php


## Sastavljanje PHP gadget chaina
[Magične metode](https://www.php.net/manual/en/language.oop5.magic.php)

Cilj je sastaviti objekt čijom se deserijalizacijom poziva niz metoda (bilo magičnih bilo običnih) koji nam daje mogućnost izvršavanja koda (ili čitanje proizvoljnih datoteka ili štogod nam je cilj)

- [primjer](https://www.programiz.com/online-compiler/1biShbvrCxvKj)

Gotovi gadget chainovi
- PHPGGC - https://github.com/ambionics/phpggc
- YSOSerial - https://github.com/frohoff/ysoserial
- Dotnet - https://github.com/pwntester/ysoserial.net
- Općenito tražiti jezik/framework + universal pop chain, gadget chain, deserialization chain


## CORS miskonfiguracije
Same Origin Policy – javascript skripta na free-bitcoin.com.ru.xyz.biz ne
može čitati moje mailove s mail.google.com čak ako ih imam otvorene u
isto vrijeme
- Ali možda želim da www.fer.hr može čitati JSON API odgovore s api.fer.hr
- Zato postoji CORS – Cross Origin Resource Sharing
- Headeri kojima se mogu otvoriti "rupe" u SOP-u
- skripta na www.fer.hr pošalje CORS preflight request na api.fer.hr (OPTIONS request)
- api.fer.hr odgovori s `Access-Control-Allow-Origin: www.fer.hr` i `Access-Control-Allow-Credentials: true`
- skripta sad pošalje zahtjev, zajedno s auth. Kolačićima, koji je htjela poslat i sad može pročitati odgovor


api.fer.hr je mogao odgovoriti i s `Access-Control-Allow-Origin: *` što dopušta svaki origin, ali onda skripta ne može slati i autentifikacijske kolačiće
- Već i to bi mogao biti sigurnosni problem ako postoji osjetljivi sadržaj kojem se može pristupiti i bez autentifikacije (npr. neke intranet stranice)
- Miskonfiguracija: dinamičko generiranje Access-Control-Allow-Origin headera
- Zamislimo da postoji vulnerable.xfer.hr postave server tako da stavi u `Access-Control-Allow-Origin` štogod je bilo u Origin headeru
- Žrtva, koja je ulogirana na vulnerable.xfer.hr posjeti malicioznu stranicu free-bitcoin.com.ru.xyz.biz
- Skripta na free-bitcoin.com.ru.xyz.biz pošalje preflight i s njim Origin header, vulnerable.xfer.hr vidi origin header i odgovori s `Access-Control-Allow-Origin: free-bitcoin.com.ru.xyz.biz` i `Access-Control-Allow-Credentials: true`
- Skripta sad može komunicirati s vulnerable.xfer.hr kao i žrtva (efektivno XSS)

### Miskonfiguracije apache
Zadatak – web "virtual host" - http://chal.platforma.hacknite.hr:12008/

## Host header – password reset abuse
- Što ako se password reset linkovi generiraju u formatu – `"https://"+$_SERVER["HOST"]+"/reset.php?token="+$token`
- Zatražimo password reset za žrtvu ali lažiramo host header tako da ima našu domenu
- Žrtvi dođe link na mail
- Ne mora nužno kliknuti link, e-mailovi imaju "link preview" feature – dobili smo žrtvin token
- Sad ga možemo iskoristiti na pravoj stranici

### Zanimljivi web zadatci
- KalmarCTF 2025 – ezv3ctf
- X3CTF 2025 – Kittyconvert
- Hacknite 2024 – web nemoguća misija
- Hacknite 2024 – baze i datoteke
- Hacknite 2024 - Multistage
