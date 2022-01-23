/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(float v, const char* brand): value(v), name(brand) {}
    //1
    //2 
    float value;
    //3
    std::string name;
};

struct SoccerBallSize                               //4
{
    T* compare(T& a, T& b) //5
    {
        if(a.value < b.value) return &a;
        if(a.value > b.value) return &b;

        return nullptr;
    }
};

struct U
{
    float danielBall { 0.0f }, anthonyBall { 0.0f };
    float decrementBallDistance(const float& updatedValue)      //12
    {
            std::cout << "U's danielBall value: " << danielBall << std::endl;
            danielBall = updatedValue;
            std::cout << "U's danielBall updated value: " << danielBall << std::endl;
            while(std::abs(anthonyBall - danielBall) > 0.001f)
            {
                anthonyBall += .1f;
            }

            std::cout << "U's danielBall updated value: " << anthonyBall << std::endl;
            return anthonyBall * danielBall;
    }
};

struct KickDistance
{
    static float kickSoccerBall(U& that, const float& updatedValue)        //10
    {
        std::cout << "U's danielBall value: " << that.danielBall << std::endl;
        that.danielBall = updatedValue;
        std::cout << "U's danielBall updated value: " << that.danielBall << std::endl;
        while( std::abs(that.anthonyBall - that.danielBall) > 0.001f)
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
                that.anthonyBall += .1f;
        }
        std::cout << "U's anthonyBall updated value: " << that.anthonyBall << std::endl;
        return that.anthonyBall * that.danielBall;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    T ballOne( 4.4f, "Wilson");                                             //6
    T ballTwo(5.5f, "Nike");                                             //6
    
    SoccerBallSize f;                                            //7
    auto* smaller = f.compare(ballOne, ballTwo); 
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "ballOne.value equals ballTwo.value " << std::endl;
    }
        
    U ballStart1;
    float updatedValue = 5.0f;
    std::cout << "kickSoccerBall ballStart's multiplied values: " << KickDistance::kickSoccerBall(ballStart1, updatedValue) << std::endl;                  //11
        
    U ballStart2;
    std::cout << "kickSoccerBall continuousDistance's multiplied values: " << ballStart2.decrementBallDistance(updatedValue) << std::endl;

    return 0;
}
