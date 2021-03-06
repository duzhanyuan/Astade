//~~ void DrawFoundEvent(cairo_t* cr, int eventNumber) [SeqGraphTab] ~~
int start = dataBase->GetSourceIndex(eventNumber);
int stop = dataBase->GetDestinationIndex(eventNumber);
int startPixel;
int stopPixel;
int yPixel = dataBase->GetTime2Y(eventNumber) - 5;

startPixel = dataBase->GetClassMiddle(start);
stopPixel = dataBase->GetClassMiddle(stop);

setColor(cr, red);

cairo_move_to(cr, startPixel, yPixel);
cairo_arc (cr, startPixel, yPixel, 3.5, 0.0, 2 * M_PI);
cairo_fill_preserve(cr);
cairo_stroke (cr);

DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), blue);
