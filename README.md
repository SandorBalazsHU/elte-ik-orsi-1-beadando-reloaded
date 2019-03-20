# elte-ik-orsi-1-beadando-reloaded
Első beadandó az ELTE IK Osztott Rendszerek Implementációja és Sepcifikációja (ORSI) tárgyához.

# Leírás

## Keretsztori:

A világ felfedezése során újabb mérföldkőhöz érkeztünk. Eljött az idő, hogy a Földet hátrahagyva, az arra kiválasztottak egy új helyen kezdjék újra mindazt, amit a kék bolygón nem, vagy csak rosszul sikerült megvalósítani, megtartva mindazt, ami az elmúlt évezredek során magasabbra emelte az emberiséget. Az ősi világ tiszteletére az új bolygót Pangeának nevezték el - utalva az összetartozásra és az eredetünkre. Új közösségek mellett a tudományos érdekeltségek is hajtották az új területre vágyókat - így nem csak új népcsoportok alapítása, de a felderítés is központi tényezőt játszott annak kiválasztásában, hogy kiknek adatik meg a lehetőség, hogy itt kezdjenek újra mindent.

A feladat nem lesz egyszerű. Ahhoz, hogy egy új civilizáció emelkedjen ki a többi közül, rengeteg mindent kell számításba venni. A megfelelő hely kiválasztásához rengeteg szempontot kell mérlegelni - ezek közül az egyik legfontosabb a környezet. Senki nem szeretne rettegésben élni, attól tartva, hogy a közeli ellenséges hordák megtámadják álmában, emellett az ivóvíz és táplálékforrások megléte is döntő a túlélés érdekében.

A Felderítők és Alapítók Szövetsége emiatt úgy határozott, hogy tudományos szempontból Téged kér fel a tiszteletbeli elnöki cím betöltésére - ezzel a Te feladatod lesz a bolygó adatainak az elemzése és az így kapott eredmények kihirdetése a túlélési esélyek szempontjából.

Nagy dolgokra vagy hivatott. A felelősség, mely alapján a kiválasztottak mérlegelik az új kolóniák helyét, a Te válladat nyomja. Az új bolygó felszínét - a Földéhez hasonlóan - nagyrészt víz borítja, ám egy - nem elhanyagolható - részét szárazföld fedi. Az itteni állapotok felmérése során tehát Hozzád került az információ, mely egy átfogó képet nyújt a felszín adottságairól - az itt rejtőző nyersanyagok, vízkészlet, növényvilág és őslakosok jelenlétéről biztosítva információt.

Ezeket az adatokat - kézenfekvő módon - egy térkép segítségével vetted szemügyre, amit a legkönnyebben hexagonális alapokon tudtál ábrázolni.

Ahhoz, hogy biztos eredménnyel tudj szolgálni, úgy érezted, nem elég a közvetlenül a kolóniák tudományos bázisainak helyét megvizsgálni - ennél átfogóbb és nagyobb területre kiterjedő vizsgálat lesz szükséges, emiatt egy környezeti felderítés mellett döntöttél. Ahhoz, hogy időt nyerhess, úgy határoztál, hogy a lehetséges helyszíneket egyszerre vizsgálod meg - így sokkal hamarabb választ kaphatsz, mintha egyesével elemeznéd az adott területeket.

## A megoldandó probléma tehát a következő:

A bemeneti fájlban (world.map) elsőként egy hexagonális (hatszögletű) rácson alapuló világ térképe található. A térképnél esetén feltesszük, hogy annak “hasznos része” az, amit a fájlból tudunk beolvasni, az összes, fájlban nem szereplő mezőre a világot körülölelő tengerként tekintünk.

A térkép hasznos részéhez meg van adva hány sorból és hány oszlopból áll (N x M), ezt követik az egyes mezők azonosítói.

A fájlban található C db. civilizáció szeretne letelepedni a világban, ehhez meg is kaptuk azoknak a mezőknek a helyét, ahol a fővárosukat kívánják megalapítani.

Annak érdekében, hogy felmérjék a környezetüket, mindenki számára ki kell számolnunk, hogy a városa körüli területnek mennyi az “értéke”. Ennek a mérésére minden egyes mezőtípushoz egy egész számot fogunk rendelni. A területi értéket az egyes mezők értékeinek összegeként fogjuk meghatározni.

A hexagonális elrendezésnek köszönhetően a környezetre tekinthetünk úgy, mint a kiinduló mezőtől legfeljebb r lépésben elérhető mezők halmazára (ennek pontosabb leírását és kiszámolását lásd a segítségnél).

A feladatunk meghatározni, hogy az egyes civilizációk körüli (r sugarú) területeknek mennyi az összértéke! Az így kiszámított eredményeket (a bemeneti civilizációk sorrendjében) írjuk ki az output.txt fájlba, minden sorba egy értéket írva!

Tekintve, hogy egy-egy ilyen számítás sok időt is igénybe vehet, ezért a megoldást párhuzamos módon készítjük el, melyben minden egyes értéket külön szálon fogunk számolni!

### Az inputfájl felépítése az alábbi:

Az első sorban két nemnegatív egész szám olvasható (jelölje ezt N és M), ezt követően egy N x M méretű, azaz N sorból és M oszlopból felépített világ térképe.

Az ezt következő N sor a térkép egy-egy sorának reprezentációját tartalmazza, pozitív egész számokat az [0..10] intervallumból szóközzel tagolva (lásd lejjebb, az alapmezőknél).

Ez után két nemnegatív egész számot lehet olvasni - az egyik a világban letelepedni kívánó civilizációk számát jelenti (C), a másik pedig azt adja meg, hogy mekkora sugarú környezetben szeretnénk vizsgálni egy-egy választott terület “értékét” (r). Feltehetjük, hogy C, r >= 0.

Ezt követően összesen C db koordináta-páros található szóközzel tagolva - minden egyes népcsoport számára azt a helyet, ahova a fővárost fogják tenni (sor- és oszlopszám a lentiekkel összhangban).
Feltehetjük, hogy az input fájl a fent leírtaknak megfelelően van kitöltve, és nem található benne pl. negatív, valós vagy olyan szám, ami nem felel meg mezőknek, pontosan annyi civilizáció van felsorolva, mint a C értéke, senki nem telepedne a térképen kívülre, erre külön ellenőrzést nem kell végezni (az ugyan oda telepedés megengedett, mivel a jelen feladatban nem lesz különbség vagy konkurenciából fakadó probléma).

A program olvassa be az adatokat, majd C folyamatot indítva számítsa ki az egyes területekhez tartozó megoldást, majd az így kapott eredményeket írja ki az output.txt fájlba. A fő szál területi értékekhez kapcsolódó számítást ne végezzen! Az egyes folyamatoknak három adatot kell megkapnia - a térképet, a kezdőpozíciót és a sugarat.

#### Egy példa bemenet (world.map):

```
6 7
4 4 4 4 4 4 4
4 1 1 4 5 5 4
4 4 1 9 4 4 5
4 8 4 6 4 0 4
4 4 8 4 4 2 2
4 4 4 4 9 4 2
2 2
2 3
5 5
```

#### Az ehhez tartozó elvárt kimenet (output.txt):

```
33
44
```

#### A fenti térkép vizuális megjelenítése:
<p align="center">
  <img src="https://raw.githubusercontent.com/SandorBalazsHU/elte-ik-orsi-1-beadando-reloaded/master/img/map_sample.png">
</p>

A fenti térkép vizuális megjelenítése
A térképen két piros X jelzi a két helyet, ahol letelepedni kívánnak a civilizációk, körülötte az egyes mezők értéke olvasható.

## Az implementációs feladat

A feladat megoldásához kiindulásnak innen tudtok letölteni egy ZIP állományt. Ebben három fájlt találtok - egy test.cpp, egy types.hpp és egy impl.cpp nevű fájlt.

A types.hpp fájlnak tartalmán nem kell változtatni - ezt csupán érdemes nagyjából átnézni, hogy mi minden található benne - a lentebbi segítségben található metódusok és osztályok prototípusát / definícióját tartalmazza.

A programozási feladat első része az impl.cpp fájlban található függvények rendes implementációja (működésüket lásd lejjebb).

A másik rész a feladathoz tartozó főprogram elkészítése (lehetőség szerint main.cpp), mely beolvassa az adatokat, elindítja a szálakat, összegyűjti a megoldást és elkészíti a kimeneti fájlt a fent leírtak alapján. Ez utóbbinál a külön szálon elindított függvény feladata a térképen a megfelelő pozíció körüli mezők összegyűjtése, majd ezek élvezeti értékeinek összegzése, és az így kapott eredmény visszaadása.

**Fontos:** A bemeneti fájlban előforduló pozícióknál a számozást (sor-oszlop) 1-től értjük, ám a programban az indexelést 0-tól fogjuk kezdeni mind a sorok, mind az oszlopok számát illetően! A konvertálást a beolvasáskor érdemes elvégezni! Pl.:

```
...
Coordinate c;
input >> c.x >> c.y;
--c.x;
--c.y;
...
```

A többi civilizáció kezdőhelyét nem ismerik az egyes szálak, így a számolásnál minden (i,j) pozíciót, amit vizsgálni fogunk az eredeti térképen jelölt mezőértékkel figyelembe venni - függetlenül attól, hogy oda költözne e másik népcsoport (azaz nem tekintjük településnek azt a mezőt, ahova más is költözne, hanem a térképből nézzük meg, milyen típusú az).

## Segítség a megoldáshoz:

### Alaptípusok:

**FIELD:** a lehetséges (alap)mezőtípusok felsorolásra.
**DIRECTION**: a 4 égtájból kiindulva 8 különböző irányt fogunk megkülönböztetni a mozgás megkönnyítésére.
**Coordinate:** egész számok reprezentációjával egy (x,y) páros.
**Tile:** Egy koordináta és a hozzá tartozó mező kettőse - a világtérkép mezői.
**Map:** a térképet reprezentáló osztály. A fenti 4 típust használja a működéséhez. Az üres térkép 0 sorból és 0 oszlopból áll.

### Az egyes, implementálandó függvények működése:

* Az alaptípusokhoz tartozó kiíró operátorok túlterhelése (sdt::ostream& operator<<) alapvetően nem szükséges (ezért van kikommentelve), de az esetleges debuggolást nagyban megkönnyítheti nektek a feladat elkészítése közben. Ezek működése elég ha valamilyen szöveges módon egyértelműen azonosítja a kapott értéket (pl. az égtájaknál rövidítés - SW, NE, N, a koordinátáknak rendezett formátum - (5,3), a mezőtípusokra a mező neve kisbetűkkel - pl. swamp).

* A koordináták összehasonlításához a bool operator<(const Coordinate& a, const Coordinate& b); függvény implementációja szükséges. Ezt értelmezzük úgy, hogy ha az a-hoz tartozó x koordináta kisebb, mint b-nek az x koordinátája, akkor a<b, ha nagyobb, akkor b<a, egyenlő esetben az y koordináták viszonya dönti el a rendezést.

* A Map típushoz el **kell** elkészíteni a beolvasáshoz használható operátort (std::istream& operator>>), mely beolvassa N és M értékét (rows_ és cols_ adattagok), majd feltölti a számok alapján a belső vektort (lásd: Map::set_tile(..)).

* A field_from_int(..) függvény a megfelelő FIELD-enum értékét adja vissza a lentebb olvasható sorszám alapján. Felhasználása a térkép beolvasására való(tipp: static_cast<>).

* A field_value(..) függvény a kapott mező értékét adja vissza a lentebb található értékek figyelembevételével.

* A tile_value(..) függvény a benne található mező típus értékét adja vissza (amit a field_value szolgáltat).

* A Map::Map() konstruktor nullára inicializálja a sorok és oszlopok számát.

* A Map::rows() függvény az eltárolt térképen található sorok számát adja meg.

* A Map::cols() függvény az eltárolt térképen található oszlopok számát adja meg.

* A Map::in_range(..) függvény eldönti egy adott x és y koordinátáról, hogy az benne van -e a térkép hasznos részében (a rows_ és cols_ felhasználásával). Ha nincs, akkor hamisat ad vissza.

* A Map::tile_at(..) függvény visszaad egy adott i és j koordinátához tartozó (világtérkép) mezőt. Amennyiben ez a térképen belül van, akkor az eltárolt értéket, ellenkező esetben FIELD::SEA típusút. A koordináta mind a két esetben a kapott i és j értéket tartalmazza.

* A Map::set_tile(..) metódus az adott i és j koordinátához tartozó (alap)mezőt állítja be a térképen - figyelembe véve azt is, hogy ez a térkép valós részéhez tartozzon (azon kívül esőt nem bánt).

* A Map::tile_in_direction(..) függvény egy kiinduló koordináta alapján visszaadja azt a (világtérkép) mezőt, amely a megadott irányban található. Fontos figyelembe venni, hogy az indexelés nem egyértelműen történik, ennek megadásához a lentebbi (térkép indexelés) kép és hozzá tartozó szöveg ad segítséget. Mivel hatszögekkel ábrázoljuk a világunkat, összesen hat irányt kell megvizsgálni - figyelembe véve mindegyik esetben, hogy páros vagy páratlan oszlopszámú mezőről indulunk ki - mivel ettől függ, hogy a mátrixos ábrázolásnak (belső map_ vector) melyik (i,j) eleme fog kelleni. Az implementáláshoz érdemes a lenti (első) ábrán megfigyelni, hogy a hat irány hogy változtatja a koordinátákat páros és páratlan oszlopszám kiindulva.

* A Map::get_tiles_in_radius(..) a lentebb leírt módszerek valamelyike alapján visszaadja egy megadott (i,j) koordinátából kiindulva az r sugarú környezetben lévő mezők listáját. Érdemes felhasználni a Map::tile_in_direction(..) metódust ennek implementálásakor.

### Az alapmezők (FIELD):

A mezők neve előtti sorszám azt is jelzi, hogy a bemeneti fájlban milyen int értékkel kerül reprezentálásra. A mező neve után annak “értékét” lehet olvasni.

```
0.  Kannibálok: -2
1.  Sivatag: 0
2.  Erdő: 3
3.  Aranybánya: 5
4.  Legelő: 2
5.  Vasérc: 2
6.  Édesvíz: 3
7.  Tengervíz: 1
8.  Mocsár: 1
9.  Település: 6
10. Gabona: 3
```

## Egyéb segítség:

A térkép reprezentálásához a (hatszög)rácsra mátrixként fogunk tekinteni. Ehhez azonban figyelembe kell venni annak elhelyezkedését és orientációját. A hatszögekre úgy tekintünk majd, hogy azoknak oldala néz “felfelé” és “lefelé”, azaz északi és déli irányba. Emiatt a kelet-nyugati irányban csúcsokkal találkozunk - itt tehát az “átjárás” nem lesz egyértelmű. Ahhoz, hogy az elhelyezkedésből adódó problémákat kezelni tudjuk, a páratlan számú oszlopokat fogjuk (megjelenítésileg) elcsúsztatni lefelé. Egy sor bejárásánál - avagy a kelet / nyugat irányú elmozdulás esetében - ha a kiindulási mező oszlopszáma páros, akkor dél-keleti / dél-nyugati irányba fogunk mozdulni, páratlan esetben pedig észak-kelet/észak-nyugat lesz az elmozdulás iránya. Az észak-dél tengelyen értelemszerűen fogunk lépkedni, az x koordináta változtatásával.

<p align="center">
  <img src="https://raw.githubusercontent.com/SandorBalazsHU/elte-ik-orsi-1-beadando-reloaded/master/img/map_indexing.png">
</p>
A térkép érdemleges részének indexelési módja

### A térkép érdemleges részének indexelési módja

A környezeti halmazt két módon is meghatározhatjuk:

A t_0 mező a kiindulási, ez jelentse az r=0 sugarú környezetet mind a két esetben.

A rekurzív definíciónál az r>0 sugarú környezet mezőit úgy kapjuk meg, hogy az (r-1) sugarú környezet mezőihez hozzávesszük az összes olyat, melyekkel az ottani mezők szomszédosak (az 1 sugár esetén ez tehát a 6 körülötte lévő mezőt jelenti, a 2 sugarú az ezek mellettit is és így tovább).

Az iteratív módszernél az r>0 környezet meghatározásához az i € [1..r] intervallum összes (egész) elemére végezzük el a következőket: A kiindulási mezőhöz képest mozduljunk el i távolságot (pl.) északi irányba! Innentől kezdve az alábbi módon kell mozognunk:

* Lépjünk i-szer dél-kelet felé
* Lépjünk i-szer dél felé
* Lépjünk i-szer dél-nyugat felé
* Lépjünk i-szer észak-nyugat felé
* Lépjünk i-szer észak felé
* Lépjünk i-szer észak-kelet felé

Ezzel az i sugarú kör szélén sétálunk végig, az összes, közbülső lépés alatt érintett mezőt pedig belevesszük az r sugarú környezet halmazába.

Szemléltetésként érdemes lehet egyfajta “körlapra” gondolni az adott mezőtől r távolságban.

Az alábbi példában a középen lévő, bordóra színezett mezőtől egy távolságra vannak a sárgával jelölt, két távolságra a zölddel, háromra a kékkel, négyre a szürkével, öttel a sötétbarnával stb. jelölt mezők.

<p align="center">
  <img src="https://raw.githubusercontent.com/SandorBalazsHU/elte-ik-orsi-1-beadando-reloaded/master/img/map_radius.png">
</p>
A környező mezők és az ahhoz tartozó sugár

A fent linkelt ZIP állományban található egy test.cpp fájl is - ezt az impl.cpp fájllal egybe fordítva és futtatva lehet (alapjaiban) ellenőrizni azt, hogy a metódusokat helyesen implementáltátok e. Ez nem teljes körű UNIT-test, csupán arra szolgál, hogy gyors visszajelzést kapjatok a kódról és az implementálandó metódusok működésének helyességéről.

Ha “mindent jól” írtatok, az alábbiakat kell látni (linuxon, g++-szal fordítva):

```
user@host:> g++ test.cpp impl.cpp -lpthread && ./a.out
Testing field values...done!
Testing field from int...done!
Testing Map constructor...done!
Testing Map::in_range()...done!
Testing Map::tile_at()...done!
Testing Map::tile_in_dir()...done!
Testing Map::set_tile()...done!
Testing Map::get_tiles_in_radius()...done!

All tests successfully passed!
``

A -lpthread flag Windowson nem szükséges, de Linux alapokon sokszor enélkül futási hibát kaphatsz, a megfelelő libek linkelésének hiánya miatt.

Ha egy civilizáció sem szeretne letelepedni (azaz C=0), akkor egy üres output.txt-t kell létrehozni (azaz ne hibakóddal térjen vissza a program).

## Általános elvárások:

Fokozottan kérünk mindenkit, hogy a beadandó határidejét (március 22, 19:59) vegye figyelembe! Kérjük osszátok be az időtöket, hogy ne csússzatok le a határidőről semmi esetben sem! Ez után nem áll módunkban elfogadni megoldásokat, kifogástól és indoklástól függetlenül! (Szült a halam, nem tudtam beadni, de elküldöm emailben; pont feltöltöttem volna, de lezárt a BEAD, jó lesz facebookon?; Késett a vonat de majd behozom pendriveon úgy jó? Nem, nem lesz jó egyik esetben sem.)

Kérünk mindenkit, hogy olvassa el a BEAD-on a hozzászólásokat, amiket írunk neki, mielőtt újra és újra feltölti a megoldást, így elkerülhető, hogy feleslegesen terheljétek a szervert, és egy körben lehet a legtöbb hibát javítani.

A megoldásaitokat egyetlen ZIP fájlba tömörítve töltsétek fel! Kérünk benneteket, hogy csak a szükséges forrásfájl(oka)t rakjátok bele az állomány gyökerébe, teljes projektet, solutiont (.cbp, .sln, illetve az ezekhez tartozó többi fájl), object fájlokat, vagy közvetlenül futtatható állományt (a.exe, a.out, etc..) semmiképp sem!

A beadandót **binárisan értékeljük**, de ettől függetlenül fogtok kapni (valószínűleg) megjegyzéseket a megoldásotokra vonatkozóan.

Javítani bármennyiszer lehet, de a határidő szoros közeledtével egyre kisebb az esély rá, hogy lesz időnk megnézni azt.
Szeretnénk mindenkit megkérni, hogy az alábbiak vegye figyelembe a feltöltés során:

* A main.cpp, impl.cpp és types.hpp fájlokat mellékeljétek a ZIPbe, de a types.hpp fájlon kérünk ne módosítsatok (ha nem muszáj)!
* A test.cpp fájlt **nem kell** feltölteni!
* A fájlokat a ZIP gyökerébe helyezzétek el, tehát ne mappát tömörítsetek, csupán a fájlokat!

#### Értékelési megjegyzés: Az automata tesztelő elutasítja a megoldást, ha az nem fordult le (ennek okát is jelezni fogja). Amennyiben fordítható, lefuttatja több különböző inputra, és összeveti a megoldásodat az elvárt kimenetekkel. Ha mindegyik egyezik (a whitespacek között nem tesz különbséget, így mindegy, hogy a sorok végén van -e plusz szóköz vagy nincs, illetve sorvégi enter az utolsó bejegyzés után), akkor a BEADon átment a megoldásod. Ez után még valamelyik oktató is ellenőrzi a megoldást - a kódot átnézve, megjegyzéseket fűzve hozzá. Ha ez is rendben van, akkor elfogadottnak minősítjük a beadandót. Ha valami problémába ütközünk (vagy a BEADon nem megy át), akkor elutasításra kerül a megoldásod. Ennek okát részletezni fogjuk.

Egyéb segítség: https://people.inf.elte.hu/mykeesg/index.php?page=orsi&year=18_19_2

Az értékelési / kódolási guide szintén az előbbi linken érhető el (FAQ és követelmények).

Az automatikus tesztelés is működik!

Ha hibát találtok a types.hpp fájlban, jelezzétek, hogy javíthassuk!