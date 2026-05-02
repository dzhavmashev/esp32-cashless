// Function : FUN_401628b8
// Address  : 0x401628b8
// Size     : 183 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401628b8(int param_1)

{
  char cVar1;
  int iVar2;
  
  FUN_40147fe4(6,0x1000,3,0x3f43581f,param_1);
  if (param_1 - 1U < 2) {
    (**(code **)(_DAT_3ffc1a34 + 0x198))(0);
  }
  else {
    (**(code **)(_DAT_3ffc1a34 + 0x198))(0,1);
    if ((DAT_3ffc1a44 == '\0') && (iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))(), iVar2 != 0)) {
      FUN_40147fe4(6,0x1000,1," %s %u\n");
      (*(code *)&SUB_40094bc8)();
    }
  }
  if (DAT_3ffca1e5 != '\0') {
    cVar1 = DAT_3ffca1d9;
    if ((_DAT_3ffca1fc == 0) && (param_1 - 1U < 2)) {
      memw();
      _DAT_3ffca1fc = param_1;
    }
    else {
      if ((param_1 != 0) || (1 < _DAT_3ffca1fc - 1U)) goto LAB_4016296c;
      _DAT_3ffca1fc = param_1;
      if (DAT_3ffca1d9 != '\0') {
        memw();
        FUN_4018bdc0();
        DAT_3ffca1d9 = '\0';
        memw();
        cVar1 = '\0';
        if (((DAT_3ffca1eb == '\0') && (cVar1 = DAT_3ffca1d9, DAT_3ffca1e6 != '\0')) &&
           (DAT_3ffca1e7 == '\0')) {
          memw();
          DAT_3ffca1d9 = '\0';
          FUN_401613ec(0);
          cVar1 = DAT_3ffca1d9;
        }
      }
    }
    DAT_3ffca1d9 = cVar1;
    FUN_4018a8a8();
    return;
  }
LAB_4016296c:
  _DAT_3ffca1fc = param_1;
  memw();
  return;
}

