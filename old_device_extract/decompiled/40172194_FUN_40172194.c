// Function : FUN_40172194
// Address  : 0x40172194
// Size     : 177 bytes


int FUN_40172194(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined8 uVar6;
  
  if (param_1[1] == 0) {
    uVar1 = (*(code *)&SUB_40094d60)(*param_1);
    param_1[1] = uVar1;
    if (uVar1 == 0) {
      uVar6 = (*(code *)&SUB_40085bfc)();
      uVar2 = FUN_401847f4(&DAT_3f424da0);
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c(" \"%s\"\r\n",uVar3,uVar2,0x43,"le");
      *(undefined1 *)(param_1 + 5) = 1;
      return 0;
    }
  }
  if ((param_1[3] != 0) && (param_1[3] == param_1[2])) {
    param_1[3] = 0;
    param_1[2] = 0;
  }
  if (((param_1[1] != 0) && (param_1[3] < *param_1)) && (iVar4 = FUN_401720e8(param_1), iVar4 != 0))
  {
    iVar4 = FUN_40109394(param_1[4],param_1[1] + param_1[3],*param_1 - param_1[3],8);
    if (-1 < iVar4) {
      param_1[3] = param_1[3] + iVar4;
      return iVar4;
    }
    piVar5 = (int *)FUN_40173a8c();
    if (*piVar5 != 0xb) {
      *(undefined1 *)(param_1 + 5) = 1;
    }
  }
  return 0;
}

