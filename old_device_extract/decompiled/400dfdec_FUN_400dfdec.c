// Function : FUN_400dfdec
// Address  : 0x400dfdec
// Size     : 76 bytes


float FUN_400dfdec(int param_1,float param_2)

{
  char cVar1;
  float fVar2;
  float *pfVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  
  cVar1 = *(char *)(param_1 + 0x78);
  fVar2 = 0.0;
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      if (*(float *)(param_1 + 0x28) <= param_2) {
        fVar2 = *(float *)(param_1 + 0x2c);
      }
    }
    else {
      pfVar3 = (float *)(param_1 + 0x28);
      cVar4 = '\0';
      fVar6 = 0.0;
      do {
        fVar5 = *pfVar3;
        if ((fVar5 <= param_2) && (fVar6 < fVar5)) {
          fVar2 = pfVar3[1];
          fVar6 = fVar5;
        }
        cVar4 = cVar4 + '\x01';
        pfVar3 = pfVar3 + 2;
      } while (cVar1 != cVar4);
    }
  }
  return fVar2;
}

