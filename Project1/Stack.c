#include "Stack.h"

/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/

Stack newStack( int maximumStackSize ){
    Element* stack = (Element*)malloc( maximumStackSize * sizeof( Element ) );

    StackImp* new = (StackImp*)malloc( (2 * sizeof(int)) + sizeof(stack));

    new->maxSize = maximumStackSize;
    new->count = 0;
    new->stackElements = stack;

    return new;

}

void freeStack( Stack s ){

    free( s->stackElements );
    free( s );

}

void push( Stack s, Element e ){
    if(s->count < s->maxSize){
        s->stackElements[s->count] = e;
        s->count++;
    }
    else{
        printf("[ERROR] cannot push to stack that contains its maximum amount of elements\n");
    }
}

Element pop( Stack s ){
    if( s->count > 0 ){
        s->count--;
        return s->stackElements[s->count];
    }
    else{
        printf("[ERROR] cannot pop from empty stack\n");
        //dont know what to return here, maybe a null element?
    }
}

int isEmpty( Stack s ){
    if( s->count <= 0 ){
        return 1;
    }
    return 0;
}

Element topElement( Stack s ){
    return s->stackElements[s->count-1];
}