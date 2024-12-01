Higher or Lower - Coding Challenge - Hawk-Eye Innovations

Candidate : George Cottrell


Why certain decisions were made:

	Engine Choice -
	
		Unreal was chosen as my engine of choice for two key reasons, The first of which is my own familiarity with the engine itself. As I come from a games background the choice 
		to use a game engine as a base for this task was only logical. Further to this I'm aware the unreal engine is used at Hawk-Eye for some of the developed technologies.

	Design / Planning -

	Before attempt to code a solution to the problem my first task was to plan out how the game features of higher or lower would work from a programmatic sense. My first undertakings 
	were to plan each of the required game functions needed to create a minimum viable product for the task at hand. This meant initially creating a flow chart for the intended functionality and design 
	implementation for the higher lower system. From this sudo code was written up in order to create a more detailed level of 	planning for the initial implementation.


	Implementation -

		Initial Implementation -

		My first attempt at an implementation was done in base C++ using a basic CLI for interaction. This was done to gain an initial understanding of how the class structure for 
		the program would be set up. From this I drew the conclusion that it would be to use two separate class or struct types for the card and deck system. The card class would 
		contain an enumerator for both the suit and value of the card. This would then be used for things such as deck construction, card value comparisons and would act as the 
		fundamental building block for the higher or lower game system.
	
		A Deck class was also made in order to handle all deck based functionality, This included things such as the creation of the deck, the shuffling of the deck and the 
		destruction of the deck (Also the destruction of the deck would not be required in the end.)

		From this a main class was then used to handle the game logic itself such as the instantiation of a deck, the handling of user input and how the game logic would react to said user input.


		Further Implementation (Unreal Engine) -

		From the initial implementation I moved on to create a basic user interface within Unreal Engine. This would be the basis for adapting the code from the initial implementation into a more function and display oriented minimum viable product.


		Card Image Handling -

		Handling the card images was something that, at first, I was unsure of how I would go about. I eventually settled on the idea of having 52 separate images locating within 
		the source directory each named with the following convention: "value_of_suit" (e.g. ace_of_clubs). GUI class would grab the relevant file reference path and use this to 
		apply the correct image to both the current and next card as and when required. This system works well despite some minor delays 	when it comes to texture streaming speed. 


		Button Functionality -

		Button functionality was something relating to unreal engine UMG system that I hadn't touched in C++ before. After some researched and in order to retain a decent level of 
		code abstraction, I decided that use a event delegate system would 	suit this section of the code best. From this each button within the UI has a respective signature and delegate. 
		These are 	the used to broadcast the respective on click events. The required functions are then linked to each event as a listener and respond according with the correct functionality as required.


Improvements:

	Shuffling Mechanics -

		The shuffling code itself is system and functional. However, the system in it current state offers no user feedback when the shuffle button is pressed. 
		The remaining cards in the deck are shuffled however there is no graphical representation of this to show the user that the shuffle has occured. One idea would be 
		to add something to represent this e.g. an animation.

	Code Abstraction -

		One area that i think would help greatly with the code I've created would be a greater level of abstraction. Applying the concepts of code polymorphism, adding 
		interfaces for the implementation of core methods for things such as the card comparison, drawinog and shuffling would be a good place to start.

	Code Structure -

		As it currently stands the code structure could be improved by further abstraction by class separation. One key area would be to segment the user interface into sub classes. 
		An example of this would be to create seperate UWidgetComponents for each of the card displays. From this the funcions for displaying cards could then be moved into this new 
		sub class giving both a more re-usable and a more easily readable code structure.

	Card Image Display -

		As stated earlier there is a known issue with a delay caused during the asset streaming process of the code. This sometimes causes a bug where the cards do not correctly display 
		meaning that cards may be visually skipped. A more efficient process for asset streaming would help to negate this issue.

	GUI -

		If the project were to be expanded in scope the inclusion of an extended user interface (e.g. Main menu with settings etc) would give the project a more complete feel with a greater level of user experience.
