// Function : FUN_400f14c4
// Address  : 0x400f14c4
// Size     : 92 bytes


uint FUN_400f14c4(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar1 = FUN_40184778(param_2);
  uVar3 = 0xffffffff;
  if (uVar1 != 0) {
    uVar3 = FUN_40184778(param_1);
    if ((uVar3 == 0) || (uVar3 < uVar1)) {
      uVar3 = 0xffffffff;
    }
    else {
      if (uVar3 <= param_3) {
        param_3 = uVar3 - 1;
      }
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        param_1 = (int *)*param_1;
      }
      uVar3 = 0xffffffff;
      piVar4 = param_1;
      while (piVar4 <= (int)param_1 + param_3) {
        piVar5 = param_2;
        if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
          piVar5 = (int *)*param_2;
        }
        iVar2 = func_0x4008ca64(piVar4,piVar5);
        if (iVar2 == 0) {
          return uVar3;
        }
        if ((uint)(iVar2 - (int)param_1) <= param_3) {
          uVar3 = iVar2 - (int)param_1;
        }
        piVar4 = (int *)(iVar2 + 1);
      }
    }
  }
  return uVar3;
}

