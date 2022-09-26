
    cin >> nodos >> caminos;
    InitMat(Mat, nodos); // to initialize the matrix
    for(int j = 0; j < caminos; j++){
      cin >> X >> Y >> C;
      Mat[X-'A'][Y-'A']= Mat[Y-'A'][X-'A'] = C;
    }