// Function : FUN_4018bb20
// Address  : 0x4018bb20
// Size     : 387 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_4018bb20(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  cVar5 = '\0';
  if (0xb < param_2 - param_1) {
    *param_4 = param_1;
    uVar4 = (uint)*(ushort *)(param_1 + 8) << 10;
    if ((*(ushort *)(param_1 + 8) == 0) && (uVar4 = 0x19000, DAT_3ffca1e8 == '\0')) {
      memw();
      FUN_40147fe4(6,0x1000,3,0x3f435a7b);
      FUN_40147fe4(6,0x1000,3,0x3f435a41);
      FUN_40147fe4(6,0x1000,3,0x3f4359f9);
      FUN_40147fe4(6,0x1000,3,0x3f4359cb);
      uVar4 = 0x19000;
    }
    pcVar2 = (char *)(param_1 + 0xc);
    while( true ) {
      if ((param_2 - (int)pcVar2 < 2) || (param_2 - (int)pcVar2 <= (int)((byte)pcVar2[1] + 1)))
      goto LAB_4018bba6;
      if (*pcVar2 == '\x05') break;
      pcVar2 = pcVar2 + (byte)pcVar2[1] + 2;
    }
    *param_3 = (int)pcVar2;
    memw();
LAB_4018bba6:
    if ((*param_3 == 0) && (DAT_3ffca1e8 == '\0')) {
      FUN_40147fe4(6,0x1000,3,0x3f4359a7);
      FUN_40147fe4(6,0x1000,3,0x3f43596d);
      FUN_40147fe4(6,0x1000,3,0x3f435925);
      FUN_40147fe4(6,0x1000,3,0x3f4358f7);
    }
    cVar1 = DAT_3ffca1e8;
    if (DAT_3ffca1e8 == '\0') {
      if (*param_3 != 0) {
        DAT_3ffca1e3 = *(char *)(*param_3 + 3);
        memw();
      }
      memw();
      _DAT_3ffca204 = uVar4;
      iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
      if ((iVar3 != 0) && (DAT_3ffca1e6 != '\0')) {
        (**(code **)(_DAT_3ffc1a34 + 0x1b8))(uVar4 / 100);
      }
      DAT_3ffca1e8 = '\x01';
      memw();
      memw();
      FUN_40147fe4(6,0x1000,3,0x3f4358c8,_DAT_3ffca204,DAT_3ffca1e3);
      cVar5 = '\x01';
    }
    else {
      if (uVar4 != _DAT_3ffca204) {
        memw();
        _DAT_3ffca204 = uVar4;
        iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
        if ((iVar3 != 0) && (DAT_3ffca1e6 != '\0')) {
          (**(code **)(_DAT_3ffc1a34 + 0x1b8))(uVar4 / 100);
        }
      }
      iVar3 = *param_3;
      cVar5 = cVar1;
      if ((iVar3 != 0) &&
         ((DAT_3ffca1e3 != *(char *)(iVar3 + 3) ||
          ((DAT_3ffca1e9 != '\0' && (cVar5 = DAT_3ffca1e9, *(char *)(iVar3 + 2) != '\0')))))) {
        memw();
        memw();
        DAT_3ffca1e3 = *(char *)(iVar3 + 3);
        cVar5 = cVar1;
      }
    }
  }
  return cVar5;
}

