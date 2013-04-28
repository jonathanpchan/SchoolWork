/*-----------------------------------------------------------------------------------------
Project: Midterm
Author: Jonathan Chan
Description: Text Class using stringVar objects
Notes: 2/18 Okay, got stuck on sorting for a while. Everything else wasnt too hard

The humans of Tyria are a proud but embattled race. Over the centuries, they hav
e lost much of their land and have even lost their gods, but the resilient human
s can adapt to seemingly any circumstances. Today, the human race maintains thei
r unshakeable spirit in the face of harrowing adversity.
Once, great human nations ruled much of Tyria, but no longer. After a protracted
 and bloody war, the charr conquered the powerful kingdom of Ascalon. The awaken
ing of the Elder Dragon known as Zhaitan triggered a massive wave that reshaped
coastlines and destroyed LionÆs Arch, the largest human city at the time.
Human refugees settled in Kryta and founded DivinityÆs Reach, a fortified metrop
olis that shines like a beacon of hope for all humans. From here, the long reach
 of human power stretches out across the surrounding countryside, offering prote
ction to farmers and townsfolk who live under constant threat from marauding cen
taurs and gangs of bandits. Not all threats to mankind are as obvious; inside th
e city walls, power struggles and intrigue between the queen and the nobility st
rain the fabric of human society.
One of the greatest setbacks humanity has experienced is the withdrawal of the S
ix Gods from their daily lives. Despite their silence, humans do not feel forsak
en; they feel as if they are being tested. The gods expect them to stand on thei
r own, and as a people, they refuse to fall.
HumanityÆs long and tragic history may lead other races to think of them as a dy
ing race that belongs to another age, but humans know otherwise. Even the younge
st sylvari knows about the great human figures of legendùand the time has come f
or a new hero to walk in their footsteps.
Your Human Character

When you create your human character, you will pick your social class. Were you
raised in high society? Perhaps you come from a hardworking middle-class backgro
und. Or did you grow up poor on the mean streets of DivinityÆs Reach? As a human
, youÆll also select one of the Six Gods as your patronùfrom Grenth, the god of
death, to Lyssa, the goddess of illusions.
When your human character increases in level, they will gain access to a range o
f special racial skills granted to them by the Six Gods, such as summoning fears
ome Hounds of Balthazar or beseeching the healing goddess Dwayna to restore your
 health.
Your story begins in Queensdale, a lush district of farmlands and rolling hills
that lies in the shadow of the great walls of DivinityÆs Reach. Here, you will a
nswer the call to adventure and create a new legend in the history of your proud
 people.
a --- 13
about --- 1
access --- 1
across --- 1
adapt --- 1
adventure --- 1
adversity --- 1
After --- 1
age --- 1
all --- 2
also --- 1
and --- 13
another --- 1
answer --- 1
any --- 1
Arch --- 1
are --- 3
as --- 8
Ascalon --- 1
at --- 1
awakening --- 1
background --- 1
Balthazar --- 1
bandits --- 1
beacon --- 1
begins --- 1
being --- 1
belongs --- 1
beseeching --- 1
between --- 1
bloody --- 1
but --- 4
by --- 1
call --- 1
can --- 1
centaurs --- 1
centuries --- 1
Character --- 3
charr --- 1
circumstances --- 1
city --- 2
class --- 2
coastlines --- 1
come --- 2
conquered --- 1
constant --- 1
countryside --- 1
create --- 2
daily --- 1
death --- 1
Despite --- 1
destroyed --- 1
did --- 1
district --- 1
Divinity --- 3
do --- 1
Dragon --- 1
Dwayna --- 1
dying --- 1
Elder --- 1
embattled --- 1
even --- 2
expect --- 1
experienced --- 1
fabric --- 1
face --- 1
fall --- 1
farmers --- 1
farmlands --- 1
fearsome --- 1
feel --- 2
figures --- 1
footsteps --- 1
for --- 2
forsaken --- 1
fortified --- 1
founded --- 1
From --- 5
gain --- 1
gangs --- 1
god --- 1
goddess --- 2
gods --- 5
granted --- 1
great --- 3
greatest --- 1
Grenth --- 1
grow --- 1
hardworking --- 1
harrowing --- 1
has --- 2
have --- 2
healing --- 1
health --- 1
here --- 2
hero --- 1
high --- 1
hills --- 1
history --- 2
hope --- 1
Hounds --- 1
human --- 11
humanity --- 2
humans --- 5
if --- 1
illusions --- 1
in --- 8
increases --- 1
inside --- 1
intrigue --- 1
is --- 1
kingdom --- 1
know --- 1
known --- 1
knows --- 1
Kryta --- 1
land --- 1
largest --- 1
lead --- 1
legend --- 2
level --- 1
lies --- 1
like --- 1
Lion --- 1
live --- 1
lives --- 1
ll --- 1
long --- 2
longer --- 1
lost --- 2
lush --- 1
Lyssa --- 1
maintains --- 1
mankind --- 1
marauding --- 1
massive --- 1
may --- 1
mean --- 1
metropolis --- 1
middle --- 1
much --- 2
nations --- 1
new --- 2
no --- 1
nobility --- 1
Not --- 2
obvious --- 1
of --- 24
offering --- 1
on --- 2
Once --- 1
One --- 2
Or --- 2
other --- 1
otherwise --- 1
out --- 1
Over --- 1
own --- 1
patron --- 1
people --- 2
Perhaps --- 1
pick --- 1
poor --- 1
power --- 2
powerful --- 1
protection --- 1
protracted --- 1
proud --- 2
queen --- 1
Queensdale --- 1
race --- 3
races --- 1
racial --- 1
raised --- 1
range --- 1
Reach --- 4
refugees --- 1
refuse --- 1
reshaped --- 1
resilient --- 1
restore --- 1
rolling --- 1
ruled --- 1
s --- 5
seemingly --- 1
select --- 1
setbacks --- 1
settled --- 1
shadow --- 1
shines --- 1
silence --- 1
Six --- 3
skills --- 1
social --- 1
society --- 2
special --- 1
spirit --- 1
stand --- 1
story --- 1
strain --- 1
streets --- 1
stretches --- 1
struggles --- 1
such --- 1
summoning --- 1
surrounding --- 1
sylvari --- 1
tested --- 1
that --- 4
The --- 34
their --- 7
them --- 3
they --- 5
think --- 1
threat --- 1
threats --- 1
time --- 2
to --- 13
Today --- 1
townsfolk --- 1
tragic --- 1
triggered --- 1
Tyria --- 2
under --- 1
unshakeable --- 1
up --- 1
walk --- 1
walls --- 2
war --- 1
wave --- 1
Were --- 1
When --- 2
who --- 1
will --- 3
withdrawal --- 1
you --- 7
youngest --- 1
Your --- 8
Zhaitan --- 1
Press <RETURN> to close this window...

-----------------------------------------------------------------------------------------*/


#include "text.h"
#include "stringvar.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{

    Text wordList(8000);

    wordList.ReadFile("test.txt");





    return 0;
}


