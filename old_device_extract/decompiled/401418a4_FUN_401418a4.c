// Function : FUN_401418a4
// Address  : 0x401418a4
// Size     : 177 bytes


int FUN_401418a4(int *param_1,byte *param_2,byte param_3,byte param_4,byte param_5,byte param_6,
                code *param_7,undefined4 param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_24 [9];
  
  memw();
  iVar2 = FUN_40141738(param_1,param_2,local_24,0x30);
  if (iVar2 == 0) {
    if (param_2 == (byte *)(*param_1 + local_24[0])) {
      while (pbVar4 = (byte *)*param_1, pbVar4 < param_2) {
        *param_1 = (int)(pbVar4 + 1);
        bVar1 = *pbVar4;
        if ((bVar1 & param_3) != param_4) {
          return -0x62;
        }
        memw();
        iVar3 = FUN_40186734(param_1,param_2,local_24);
        if (iVar3 != 0) {
          return iVar3;
        }
        if ((((bVar1 & param_5) == param_6) && (param_7 != (code *)0x0)) &&
           (iVar3 = (*param_7)(param_8,bVar1,*param_1,local_24[0]), iVar3 != 0)) {
          return iVar3;
        }
        *param_1 = *param_1 + local_24[0];
        memw();
      }
    }
    else {
      iVar2 = -0x66;
    }
  }
  return iVar2;
}

