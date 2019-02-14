# Overview of functions
## Requirements
### Must
|ID|Omschrijving|Punten|
|---|---|---|
|SA01|Elke vrijheidsgraad moet worden ontsloten, waarbij de bijbehorende servo’s naar de opgegeven positie (hoek, in graden) kunnen worden verplaatst.|4|
|PO01|Park: Een positie waarin de arm veilig kan worden uitgeschakeld.|3|
|VE01|Noodstop: De arm wordt zo snel mogelijk gestopt, waarbij de huidige actie wordt afgebroken. Alle openstaande acties van de robotarm worden geannuleerd|5|
|INF01|De interface geeft toegang tot informatie over de operationele toestand Van het arm-systeem via rosout op INFO niveau. De weergegeven toestanden moeten overeenkomen met de toestanden van de protocol state machine bij US02. De informatie wordt geboden in het volgende formaat “STATE: {statename}”.|3|
|INF02|Geef event informatie via rosout op DEBUG niveau. Hierbij zijn in ieder geval de events opgenomen zoals zichtbaar zijn in de protocol state machine bij US02. De informatie wordt geboden in het volgende formaat “EVENT: {eventname}”.|3|
|SY01|Use cases, inclusief decompositie in subsystemen.|4|
|US02|Inzicht in resource beschikbaarheid in de vorm van stateafhankelijke beperkingen en geboden functies (events waar op gereageerd kan worden) op basis van een Protocol State Machine behorende bij de high level interface.|4|
|IM01|De software biedt een high-level interface die de vereiste functionaliteit ontsluit via de ROS-communicatieinfrastructuur (topics, services, actions etc.).|4|
|IM02|De software bevat een interne low-level driver (in de vorm van een Dynamically Linked Library voor het direct ontsluiten van de bestaande functies van de robotarm. Dit is een 1-op-1 koppeling met de door de hardware geboden functies die benodigd zijn voor de implementatie van de gevraagde functionaliteit.|4|
|IM05|De applicatie is te bouwen met catkin op ROS Melodic Morenia.|1|
|IM06|De applicatie wordt gebouwd met C++-14.|1|
|DE01|De demo gebruikt de interface om de robotarm het volgende scenario te laten doorlopen: <br>• Opstart en initialisatie.<br>• Korte pauze.<br>• Voorgeprogrammeerde posities: Ready en Straight up.<br>• Verschillende opeenvolgende armverplaatsingen naar verschillende locaties.<br>• Noodstop (werking moet duidelijk zichtbaar zijn).<br>• Park.|4|
|Totaal:||40|
### Should
