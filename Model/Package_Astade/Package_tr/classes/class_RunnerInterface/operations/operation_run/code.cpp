//~~ void run() [RunnerInterface] ~~
unsigned int currentTimeout;

while (currentSection->hasLines()) 
{
    while(currentSection->checkTrigger(inputBuffer, 0, currentTimeout))
    ;
    
    if (!currentSection->hasLines())
        currentSection->nextSection();
    else
        inputBuffer += readChar(0);

    while(currentSection->checkTrigger(inputBuffer, 0, currentTimeout))
    ;
};