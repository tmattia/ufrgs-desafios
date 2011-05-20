#include <algorithm>  // copy()
#include <fstream>    // fstream
#include <iostream>   // cout
#include <iterator>   // istream_iterator, ostream_iterator, back_inserter
#include <sstream>    // istringstream
#include <string>     // string
#include <vector>     // vector
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int num_people;
        cin >> num_people;

        vector<int> here;
        while (num_people--) {
            int time;
            cin >> time;
            here.push_back(time);
        }
        sort(here.begin(), here.end());

        int total_time = 0;
        vector<int> trips;

        // limit cases
        if (here.size() == 1) {
            cout << here[0] << endl << here[0] << endl;
        } else if (here.size() == 2) {
            cout << here[1] << endl << here[0] << " " << here[1] << endl;
        } else {
            // standard case
            int a, b, y, z, time1, time2;
            while (here.size() > 0) {
                if (here.size() == 1) {
                    trips.pop_back();
                    total_time -= here[0];
                    break;
                } else if (here.size() == 2) {
                    trips.push_back(here[0]);
                    trips.push_back(here[1]);
                    total_time += here[1];
                    break;
                }
                a = here[0];
                b = here[1];
                y = here[here.size() - 2];
                z = here[here.size() - 1];
                time1 = b + a + z + b;
                time2 = z + a + y + a;
                if (time1 < time2) {
                    trips.push_back(a); trips.push_back(b);
                    trips.push_back(a);
                    trips.push_back(y); trips.push_back(z);
                    trips.push_back(b);
                    total_time += time1;
                } else {
                    trips.push_back(a); trips.push_back(z);
                    trips.push_back(a);
                    trips.push_back(a); trips.push_back(y);
                    trips.push_back(a);
                    total_time += time2;
                }
                here.pop_back();
                here.pop_back();
            }

            cout << total_time << endl;

            int i = 0;
            while (trips.size() > 0) {
                if (i % 2 == 0) {
                    cout << trips[0] << " " << trips[1] << endl;
                    trips.erase(trips.begin());
                    trips.erase(trips.begin());
                } else {
                    cout << trips[0] << endl;
                    trips.erase(trips.begin());
                }
                i++;
            }
        }


        if (cases > 0) cout << endl;
    }

    return 0;
}
