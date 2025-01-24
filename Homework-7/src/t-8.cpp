int counter = 100;
// initial state of counter is bigger then reference value,
// so it will never enter into while loop
while (counter < 10)
{
    cout << "counter now: " << counter;
    counter--;
    // and even if it will enter with different initial value
    // it will never end's because we're cheching if it less
    // and using decrementor inside
}
