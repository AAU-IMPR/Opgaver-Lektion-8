# Opgaver til IMPR Lektion 8

## Relevante videoer
Til opgave A og B kan det være relevant at tage et kig på videoerne om CMake og CTest:
 - [Intro til CMake](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-intro-cmake-flere-filer&course-id=impr&lecture-number=8&course-year=2026)
 - [Intro til CTest](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-ctest&course-id=impr&lecture-number=8&course-year=2026)
 - [Programbibliotek i CMake](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-cmake-library&course-id=impr&lecture-number=8&course-year=2026)

Til opgave C kan det desuden være relevant at kigge på videoen om [unit testing frameworks](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-cmake-mtest&course-id=impr&lecture-number=8&course-year=2026).

Opgave E bliver introduceret i [denne video](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-intro-opgaver-maaltid&course-id=impr&lecture-number=8&course-year=2026).


## Gruppeopgaver
Disse opgaver laves sammen i gruppen. Der er rigeligt med opgaver.
Arbejd grundigt med de opgaver, I kan nå, i den skemalagte tid.

### Opgave A: Kom godt i gang med CTest
I filerne [src/point_distance.c](src/point_distance.c) og [src/point_distance.h](src/point_distance.h) er der implementeret funktioner til at beregne
afstanden imellem to punkter. 
Bemærk også her hvordan dokumentationen af de to funktioner er skrevet.
Versionen `point_distance_2d` kan kun beregne afstanden i 2 dimensioner, imens `point_distаnce` kan beregne det for et
vilkårligt antal dimensioner.
`point_distаnce` er dog implementeret forkert, det kan vi se ved at køre de implementerede tests som du finder i [test](test) mappen.
Specifikt er vores testprogrammer implementeret i [test/test_point_distance_2d.c](test/test_point_distance_2d.c) og [test/test_point_distance_nd.c](test/test_point_distance_nd.c).
Testene bliver "orkestreret" fra vores [test/CMakeLists.txt](test/CMakeLists.txt) fil.

Du kører testen ved at vælge "All CTest" og "kør" eller "debug":

![all_ctest.png](all_ctest.png)

Hvis du ikke ser denne mulighed, kan du tilføje den ved: "Edit configurations..." -> tryk på '+' oppe til venstre (Add new configuration) -> "CTest Application".

Ret fejlene i `point_distаnce` så vores tests går igennem.

---
### Opgave B: Test af programmet der beregner timer, minutter og sekunder
Implementeres i [src/time_calc.c](src/time_calc.c) og [src/time_calc.h](src/time_calc.h) filerne.
Husk at tilføje dem til [src/CMakeLists.txt](src/CMakeLists.txt) som et library, se hvordan det er gjort for den tidligere opgave.
Der er allerede implementeret en prototype i [src/time_calc.h](src/time_calc.h), men både implementation og dokumentation mangler.

> Vi har i rigt mål beskæftiget os med et [program](https://homes.cs.aau.dk/~normark/impr-c/intro-circle-example-slide-exercise-1.html), der beregner timer, minutter og sekunder af et antal sekunder. 
> Senest har vi i [Lektion 6 Opgave A](https://homes.cs.aau.dk/~normark/impr-c/more-functions-ex-output-pars-slide-exercise-2.html) programmeret en funktion `hours_minutes_seconds`, som er et godt udgangspunkt for denne opgave.
> 
> Lav nu en systematisk test (black box unit testing) af følgende ønskede input og outputs til funktionen `hours_minutes_seconds`:
> 
> - Input: 4000 sekunder. Forventet output: 1 timer, 6 minutter og 40 sekunder
> - Input: 75 sekunder. Forventet output: 0 timer, 1 minutter og 15 sekunder
> - Input: 3700 sekunder. Forventet output: 1 timer, 1 minutter og 40 sekunder
> - Input: 55 sekunder. Forventet output: 0 timer, 0 minutter og 55 sekunder
> - Input: 3661 sekunder. Forventet output: 1 timer, 1 minutter og 1 sekunder
> 
> Programmer dine tests ved brug af CTest og asserts, præcis som det er gjort for den tidligere opgave.
> 
> Bemærk lige at vi i denne opgave ikke tester output formatet - kun beregningerne af normaliserede timer, minutter og sekunder.

---
### Opgave C: Kom godt i gang med et unit testing framework
I de foregående to opgaver har du lært at bruge CTest og assert til at skrive unit test af et program.
Hvis man laver mange test af store programmer, er det rart at have lidt flere hjælpemidler. 
Testing frameworks gør det simplere at "orkestrere" sine test, og de har dedikerede funktioner (eller macroer) til at teste forskellige betingelser.  

Du skal nu løse opgave A og B ved hjælp af et testing framework i stedet for rå CTest og assert.
Jeg har lavet et simpelt testing framework, som jeg anbefaler at du bruger til denne opgave: [mtest](https://github.com/MortenSchou/mtest/).
(Du må også gerne forsøge dig med et af de mere komplekse og populære alternativer så som 
[Boost.Test](https://github.com/boostorg/test), [Catch2](https://github.com/catchorg/Catch2), [doctest](https://github.com/doctest/doctest) eller [Google Test](https://github.com/google/googletest).) 

Nederst i [test/CMakeLists.txt](test/CMakeLists.txt) har jeg ved hjælp af filen [cmake/mtest.cmake](cmake/mtest.cmake) installeret [mtest](https://github.com/MortenSchou/mtest/),
og gjort klar til unit test af point_distance i filen [test/unittest_point_distance.c](test/unittest_point_distance.c), 
hvor du selv skal skrive de resterende test cases ved brug af et testing framework.

Til unit testing (med et framework) af `hours_minutes_seconds` skal du selv skrive test cases i en ny fil og tilføje en test executable i [test/CMakeLists.txt](test/CMakeLists.txt) - se hvordan det er gjort for point_distance. 

---
### [Opgave D](src/puzzle.c): Wolf, goat and cabbage problem
> I denne klassiske flodkrydsningsgåde, har en rejsende landmand en ulv, en ged og et kålhoved med sig, da han møder en flod som skal krydses med en lille båd. 
> Båden er så lille at han kun kan medbringe én af sine tre egendele (ulv, ged og kål) ad gangen. 
> Han kan ikke efterlade ulven og geden alene, da ulven så vil spise geden. Han kan heller ikke efterlade geden alene med kålhovedet, da geden så vil spise kålhovedet.
> Gåden spørger hvordan manden kan få alle sine tre egendele med over på den anden side af floden.

Opgaven er ikke at løse gåden (det må I selvfølgelig stadig gerne se om I kan). 
Opgaven er til gengæld at færdiggøre den implementation af gåden, jeg har startet i filen [src/puzzle.c](src/puzzle.c).

Her skal I definere en enum type med værdier svarende til landmandens egendele `wolf`, `goat` og `cabbage`, samt værdien `none` til at indikere fraværet af en egendel.
Desuden skal I implementere funktionerne `is_safe(side)` og `all_items_on(side)`, hvor I gør brug af enum værdierne til at implementere logikken i gåden. 

Note: I [src/CMakeLists.txt](src/CMakeLists.txt) er `add_executable(puzzle puzzle.c)` kommenteret ud for at der ikke kom fejl-beskeder mens du arbejdede med de andre opgaver.
Når du begynder på denne opgave skal du fjerne `#` foran `add_executable(puzzle puzzle.c)` for at kunne køre programmet.

---
### [Opgave E](src/menu.c): En tilfældig menu
Dette er Kurt Nørmark's [opgave 8.1](https://homes.cs.aau.dk/~normark/impr-c/types-enumeration-typer-3-slide-exercise-1.html). 
Det er en forholdsvis ligefrem opgave om enumeration typer.
Implementeres i [src/menu.c](src/menu.c).

> Definer tre forskellige enumeration typer for hhv. forret, hovedret og dessert.
> 
> Enumeration typen forret skal indeholde værdier for _guacamole_, _tarteletter_, _lakserulle_ og _græskarsuppe_.
> 
> Enumeration typen hovedret skal indeholde værdier for _gyldenkål_, _hakkebøf_, _gullash_ og _forloren hare_.
> 
> Enumeration typen dessert skal indeholde værdier for _pandekager med is_, _gulerodskage_, _choklademousse_, og _citronfromage_.
> 
> Undgå dog danske bogstaver i dit C program. Det giver kun besvær!
> 
> Skriv en funktion `maaltid`, som vælger og udskriver én tilfældig ret i hver af de tre kategorier. Læs om "tilfældige tal" i C [her](https://homes.cs.aau.dk/~normark/impr-c/types-slide-rand-numbers.html).
> 
> Kald funktionen `maaltid` 25 gange i `main`, med det formål at få genereret et menukort af 25 kombinationer af forret, hovedret og dessert.
> 
> Overvej om der skal defineres flere små funktioner, som nedbryder det samlede problem i delproblemer.

---
## Hjemmeopgaver
Dette er opgaver, som I kan arbejde med derhjemme.
Enten som forberedelse inden lektionen, eller som afrunding og repetition efter lektionen.

### [Opgave F](src/opgave-f.c)
Dette er opgave 15 side 332 i Problem Solving and Program Design in C, eighth edition.
Du kan skrive dit program i filen [`opgave-f.c`](src/opgave-f.c).

Vær sikker på at du skriver en funktion med passende parametre, som returnerer pi.

> The value for $\pi$ can be determined by the series equation:
> 
> $$\pi = 4 \times (1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \frac{1}{9} - \frac{1}{11} + \frac{1}{13} - \dots)$$
> 
> Write a program that prompts the user to enter the number of iterations to be executed to determine the value of $\pi$.

### Ekstra opgave
Del din kode fra opgave F op så du får et bibliotek (library) der indeholder funktionen `double calc_pi(int iterations)`, 
og et program (executable) som håndterer interaktionen med brugeren og benytter `calc_pi` fra dit nye bibliotek.
Tilføj en unit test på at den beregnede værdi for pi er et sted imellem 3 og 4.
