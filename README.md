# Pazymiuskaiciuokle

Programa skirta apskaičiuoti studento vidurkį/medianą, pagal įvestus, atsitiktinai sugeneruotus arba iš failo nuskaitytus namų
darbų ir egzamino rezultatus.

# Veikimo principas

Vartotojas turi pasirinkti kaip nori vygdyti programa:
Skaicius vedant manualiai
Skaicius generuojant atsitiktinai
Skaicius skaitant is failo

Vartotojas pasirenka ar rezultatų nori su išvestu vidurkiu ar mediana.

Vartotojas gali pasirinkti pagal ką bus rikiuojamas sąrašas (vardą ar pavardę)

# Vartotojas pasirinkęs duomenų įvedimą rankiniu būdų:

Turi įvesti kiekvieno studento vardą bei pavardę.
Gali pasirinkti, ar namų darbų rezultatus taip pat ves rankiniu būdu, ar generuos atsitiktinai, jei veda rankiniu būdų, vartotojas gali tai daryti iki kol įveda "-1"
Vartotojui pasiūloma sugeneruoti arba rankiniu būdu įvesti egzamino rezultatą.
Vartotojo paklausiama ar dar bus vedamų studentų, jei taip, programa prasideda iš naujo ir vartotojas vėl gali arba rankiniu būdu
arba naudodamas programos sugeneruotus rezultatus pildyti studentų sąrašą.

Pasirinkus nebevesti daugiau studentų, programos lange parodoma kiek laiko truko vargšiukų (galutinis balas < 5) ir kietekų (galutinis balas >= 5) failų (txt) užpildymas.
Vartotojas tuomet gali pasirinkti pagal ką rūšiuoti visą sąrašą. (vardai arba pavardės)
Programa ekrane išspausdina išrūšiuotą studentų sąrašą. (vardas, pavardė, pasirinktas galutinis rezultatas)

# Vartotojas pasirinkęs duomenų išvedimą iš tekstinio failo

Vartotojas turi įvesti failo, iš kurio programa ims studentų sąrašą pilną pavadinimą (pvz "studentai.txt")
Vartotojas turi pasirinkti ar programa išves vidurkius ar medianas ir pasirenka pagal ką rūšiuoti sąrašą.

# Pažymius vartotojas turi įvesti po vieną, po kiekvieno įvesto spausti ENTER. 
# Galutinis vidurkis skaičiuojamas pagal formulę (galutinis = 0,4*virukis/mediana + 0,6*egzaminas)
# Programa studentų sąrašą suskaido ir išspausdina į du failus (iki 5 galutinis, nuo 5 galutinis)

# Klaidų aptikimas, veikimo instrukcija
Paleidus programa žiūrėkite į ekraną ir sekite instrukcijas.
Įvedus prie vardo skaičių ar simbolį būsite ispėjamas apie klaidingą įvesti ir galėsite pakartoti.
Įvedus prie rezultatų raidę, simbolį, skaičių virš 10 ar 0 būsite ispėjamas apie klaidingą įvestį ir galėsite pakartoti.
Taip ir ne klausimą atsakę klaidingai taip pat būsite ispėjamas ir galėsite pakartoti.

# Įdiegimo instrukcija
Atsisiuskite norimą programos versiją iš releases arba iš repositories. Rekomenduojame naujausią versiją.

# Versijos
v0.1 Pirmoji versija, programa veikia su C tipo masyvais arba vektoriais. Spausdina sąrašą sugeneruotų arba ranka įvestų studentų.
v0.2 Programa gali imti studentų duomenis iš failo (kursiokai.txt), taip pat galima rūšiuoti pagal vardus arba pavardes.
v0.3 Programa suteikia galimybę vartotojui įrašyti failo pavadinimą, iš kurio bus imamas studentu sąrašas, patikrinama ar
toks failas egzistuoja, sukurtas header bei source failas.
v0.4 Pilnai nerealizuota versija, gali surūšiuoti studentų duomenis į vargšiukus (galutinis < 5) ir kietekus (galutinis >= 5), bei 
spausdina juos į atskirus failus. Taip pat programa suskaičiuoja laiką, failų perskaitymui bei studentų rušiavimui į dvi minėtas grupes.
