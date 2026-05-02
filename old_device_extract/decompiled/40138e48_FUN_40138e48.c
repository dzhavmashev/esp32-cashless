// Function : FUN_40138e48
// Address  : 0x40138e48
// Size     : 184 bytes


int FUN_40138e48(undefined4 *param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_401864c4(*param_1);
  iVar4 = -3;
  if ((param_3 < 0x401) && (iVar4 = -5, param_5 < 0x101)) {
    if ((param_1[0x17] != 0) && ((param_1[0x15] == 1 || ((int)param_1[0x16] < (int)param_1[0x13]))))
    {
      memw();
      iVar4 = FUN_40138e30(param_1,param_4,param_5);
      if (iVar4 != 0) {
        return iVar4;
      }
      param_5 = 0;
    }
    if (((param_4 == 0) || (param_5 == 0)) ||
       (iVar4 = FUN_40138c20(param_1,param_4,param_5), iVar4 == 0)) {
      puVar2 = param_1 + 3;
      for (; param_3 != 0; param_3 = param_3 - iVar4) {
        iVar4 = (param_3 < uVar1) * param_3 + (param_3 >= uVar1) * uVar1;
        iVar3 = FUN_401393f0(param_1);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = FUN_4013935c(param_1,puVar2,uVar1);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = FUN_4013937c(param_1,puVar2);
        if (iVar3 != 0) {
          return iVar3;
        }
        (*(code *)&SUB_4008b3d0)(param_2,puVar2,iVar4);
        param_2 = param_2 + iVar4;
      }
      memw();
      iVar4 = FUN_40138c20(param_1,param_4,param_5);
      if (iVar4 == 0) {
        param_1[0x13] = param_1[0x13] + 1;
        memw();
      }
    }
  }
  return iVar4;
}

