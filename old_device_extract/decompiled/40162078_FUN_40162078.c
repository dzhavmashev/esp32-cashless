// Function : FUN_40162078
// Address  : 0x40162078
// Size     : 369 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162078(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  undefined8 uVar4;
  
  if (((DAT_3ffc1a44 == 0) || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
LAB_401620b8:
    if (param_2 == 1) goto LAB_4016209d;
    bVar3 = 0;
  }
  else {
    if (param_2 != 0) {
      (*_DAT_3ffc7a2c)(param_1,param_2,DAT_3ffca1e1);
      goto LAB_401620b8;
    }
LAB_4016209d:
    FUN_40161130();
    bVar3 = 1;
  }
  if (((DAT_3ffca1e6 == '\0') || (DAT_3ffca1e7 != '\0')) || ((param_1 == 0 && (0xf < DAT_3ffca1e1)))
     ) {
    bVar3 = 1;
  }
  if (((DAT_3ffc1a44 <= bVar3) && (iVar2 = FUN_4018c018(), iVar2 == 0)) && (DAT_3ffca1e5 == '\0')) {
    return;
  }
  if ((DAT_3ffca1eb != '\0') || (DAT_3ffca1ec != '\0')) {
    cVar1 = (char)param_1;
    if (bVar3 == 0) {
      if (param_1 == 0) {
        if (DAT_3ffca1eb != '\0') {
          memw();
          memw();
          DAT_3ffca1eb = cVar1;
          uVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
          iVar2 = FUN_40161a3c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),5000);
          if (iVar2 == 0) goto LAB_401621a8;
          DAT_3ffca1e1 = DAT_3ffca1e1 + 1;
          memw();
          memw();
LAB_401621d6:
          memw();
          FUN_401613ec(param_1);
          return;
        }
      }
      else if ((param_1 == 1) && (DAT_3ffca1ec != '\0')) {
        DAT_3ffca1ec = '\0';
        memw();
        if (DAT_3ffca1f0 != '\0') {
          DAT_3ffca1e2 = DAT_3ffca1e2 + '\x01';
          memw();
          goto LAB_401621d6;
        }
        DAT_3ffca1e2 = '\0';
        memw();
        memw();
        DAT_3ffca1f1 = cVar1;
        FUN_401612fc();
      }
    }
    else {
      if (DAT_3ffca1d9 != '\x01') {
        FUN_4018bdc0();
      }
      if (param_1 == 0) {
        memw();
        DAT_3ffca1e1 = 0;
        if (DAT_3ffca1eb != '\0') {
          memw();
          DAT_3ffca1eb = cVar1;
          if (DAT_3ffca1f0 != '\0') {
            memw();
            memw();
            DAT_3ffca1d9 = cVar1;
            DAT_3ffca1e1 = cVar1;
            DAT_3ffca1ea = cVar1;
            FUN_4018a8a8();
            _DAT_3ffc7c30 = _DAT_3ffc7c30 + 1;
            memw();
            FUN_401636d0();
            return;
          }
LAB_401621a8:
          DAT_3ffca1e1 = cVar1;
          DAT_3ffca1f1 = 1;
          memw();
          memw();
          return;
        }
      }
      else {
        DAT_3ffca1e2 = '\0';
        memw();
        if (DAT_3ffca1ec != '\0') {
          DAT_3ffca1ec = 0;
          memw();
          memw();
          FUN_401612fc();
          _DAT_3ffc7c2c = _DAT_3ffc7c2c + 1;
          memw();
          return;
        }
      }
    }
  }
  return;
}

