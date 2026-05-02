// Function : FUN_40186cc0
// Address  : 0x40186cc0
// Size     : 91 bytes


void FUN_40186cc0(char *param_1,char param_2)

{
  int iVar1;
  char cVar2;
  
  if (param_2 != 0x7f) {
    cVar2 = '\0';
    if (*param_1 != 0x7f) {
      cVar2 = (char)((uint)((int)*param_1 + (int)param_2) >> 1);
    }
    *param_1 = param_2;
    memw();
    if (param_1[1] != 0x7f) {
      iVar1 = param_1[1] * 3 + (int)cVar2;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      param_1[1] = (char)(iVar1 >> 2);
      memw();
      memw();
      return;
    }
    param_1[1] = cVar2;
    memw();
  }
  memw();
  return;
}

