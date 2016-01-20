#include <random>

#include "vocal.h"
#include "soundio.h"
#include "formants.h" // linear()

fpoint srcwave[468] =
{
    0.04334, 0.10672, 0.16138, 0.20859, 0.25742, 0.28913,
    0.31986, 0.36320, 0.41169, 0.46217, 0.50002, 0.54268,
    0.58052, 0.60576, 0.62871, 0.65493, 0.68401, 0.70180,
    0.71960, 0.73836, 0.76067, 0.78008, 0.80078, 0.80789,
    0.82568, 0.83666, 0.84445, 0.84768, 0.84573, 0.85220,
    0.86514, 0.87451, 0.88681, 0.90136, 0.90460, 0.91656,
    0.92077, 0.92401, 0.93725, 0.94082, 0.94244, 0.95376,
    0.95956, 0.96216, 0.97638, 0.97833, 0.97867, 0.98093,
    0.98157, 0.98254, 0.97833, 0.98480, 0.98706, 0.98996,
    0.99158, 0.99872, 1.00000, 0.99191, 0.99387, 0.99127,
    0.99643, 0.98834, 0.98996, 0.99319, 0.99838, 0.99710,
    0.99094, 0.98740, 0.98642, 0.97446, 0.97250, 0.97412,
    0.97250, 0.97348, 0.97543, 0.97705, 0.97510, 0.96667,
    0.95795, 0.94244, 0.93402, 0.93789, 0.93823, 0.93661,
    0.93466, 0.93725, 0.93789, 0.92367, 0.90719, 0.90783,
    0.90558, 0.89779, 0.89651, 0.88647, 0.88778, 0.89456,
    0.88940, 0.88162, 0.87127, 0.86612, 0.85705, 0.84960,
    0.84283, 0.83248, 0.82955, 0.82730, 0.81985, 0.81243,
    0.80465, 0.79397, 0.78686, 0.77911, 0.76748, 0.76034,
    0.75518, 0.74999, 0.74190, 0.73836, 0.72897, 0.71282,
    0.70666, 0.70440, 0.69341, 0.68239, 0.67852, 0.66881,
    0.65749, 0.64974, 0.64391, 0.62905, 0.61287, 0.60027,
    0.59734, 0.58571, 0.57311, 0.57018, 0.55400, 0.54076,
    0.53008, 0.52135, 0.51164, 0.49870, 0.48674, 0.48674,
    0.46831, 0.44987, 0.44276, 0.43272, 0.42497, 0.42045,
    0.40297, 0.39393, 0.38261, 0.36418, 0.35286, 0.33375,
    0.32179, 0.30918, 0.29688, 0.29203, 0.27815, 0.27103,
    0.25291, 0.23511, 0.21766, 0.20441, 0.19050, 0.16849,
    0.15201, 0.13294, 0.11158, 0.09604, 0.07407, 0.04657,
    0.02554, 0.00485, -0.02005, -0.04593, -0.07147, -0.09540,
    -0.11805, -0.13453, -0.15329, -0.17627, -0.20310, -0.22703,
    -0.25031, -0.27393, -0.29109, -0.30497, -0.32472, -0.33860,
    -0.35575, -0.37321, -0.38777, -0.41008, -0.43144, -0.44826,
    -0.46605, -0.47478, -0.48479, -0.50160, -0.51360, -0.52718,
    -0.53850, -0.55141, -0.56630, -0.58473, -0.59798, -0.61513,
    -0.62905, -0.63421, -0.64229, -0.65072, -0.65233, -0.65880,
    -0.66720, -0.66655, -0.67141, -0.67077, -0.67464, -0.68273,
    -0.68239, -0.68725, -0.68758, -0.69405, -0.70602, -0.71474,
    -0.71767, -0.72802, -0.72964, -0.72347, -0.73092, -0.73513,
    -0.73965, -0.74483, -0.75259, -0.75872, -0.76034, -0.76357,
    -0.77068, -0.77490, -0.77685, -0.78008, -0.78460, -0.78494,
    -0.78915, -0.79464, -0.79656, -0.79464, -0.80273, -0.80435,
    -0.81372, -0.82147, -0.81793, -0.82018, -0.82696, -0.82470,
    -0.82925, -0.83312, -0.83312, -0.84283, -0.84411, -0.84152,
    -0.85415, -0.86254, -0.86386, -0.86224, -0.86126, -0.86093,
    -0.86416, -0.86190, -0.86254, -0.86966, -0.87259, -0.87420,
    -0.87548, -0.88131, -0.88324, -0.88714, -0.88583, -0.88876,
    -0.89132, -0.89843, -0.90039, -0.89682, -0.89911, -0.89877,
    -0.89651, -0.90265, -0.90814, -0.90460, -0.90201, -0.89877,
    -0.89941, -0.91171, -0.91656, -0.91849, -0.92108, -0.92044,
    -0.91366, -0.91430, -0.91269, -0.90976, -0.91205, -0.91559,
    -0.91397, -0.91946, -0.92303, -0.92529, -0.92108, -0.91849,
    -0.93048, -0.93628, -0.92495, -0.91818, -0.91592, -0.92401,
    -0.92334, -0.91980, -0.92367, -0.92950, -0.92917, -0.92657,
    -0.92886, -0.92755, -0.92529, -0.91946, -0.92367, -0.93274,
    -0.93240, -0.92724, -0.92886, -0.92917, -0.92206, -0.92303,
    -0.91592, -0.91754, -0.92141, -0.91461, -0.92239, -0.92465,
    -0.92077, -0.91397, -0.91073, -0.90912, -0.91366, -0.91754,
    -0.91009, -0.90588, -0.89941, -0.90103, -0.91107, -0.91009,
    -0.90750, -0.90912, -0.90396, -0.89294, -0.90329, -0.90460,
    -0.89196, -0.88778, -0.88455, -0.88391, -0.88162, -0.87127,
    -0.86901, -0.87127, -0.86804, -0.87484, -0.87774, -0.86966,
    -0.87161, -0.86999, -0.86706, -0.86450, -0.86062, -0.85479,
    -0.85510, -0.85025, -0.84347, -0.84539, -0.84216, -0.83474,
    -0.83248, -0.82601, -0.81597, -0.81338, -0.80920, -0.81210,
    -0.80367, -0.79882, -0.79882, -0.79980, -0.79528, -0.78686,
    -0.77944, -0.77200, -0.77877, -0.76907, -0.75872, -0.75033,
    -0.74999, -0.74645, -0.74160, -0.73189, -0.72542, -0.72088,
    -0.71734, -0.71184, -0.70730, -0.70342, -0.70214, -0.69759,
    -0.69372, -0.69179, -0.67983, -0.67336, -0.66008, -0.65038,
    -0.64974, -0.65264, -0.64229, -0.63842, -0.63488, -0.62258,
    -0.61483, -0.60674, -0.59606, -0.58669, -0.58184, -0.57988,
    -0.57826, -0.56856, -0.56435, -0.56081, -0.54497, -0.53203,
    -0.52812, -0.52522, -0.52425, -0.51845, -0.50160, -0.49257,
    -0.48350, -0.48448, -0.48286, -0.47414, -0.45860, -0.45021,
    -0.44276, -0.43822, -0.43660, -0.42531, -0.41884, -0.41948,
    -0.40977, -0.38874, -0.36512, -0.34800, -0.33311, -0.31046,
    -0.29139, -0.27653, -0.24482, -0.20246, -0.13938, -0.06986
};

fpoint osc_get_sample(fpoint x)
{
    int len = 468;
    int ind1 = int(x * len);
    return linear(srcwave[ind1], srcwave[ind1 + 1], x, ind1, ind1 + 1);
}

std::default_random_engine noise_generator;
std::normal_distribution<fpoint> gauss_distribution(-1.0, 1.0);

fpoint osc_noise()
{
    return gauss_distribution(noise_generator);
}
