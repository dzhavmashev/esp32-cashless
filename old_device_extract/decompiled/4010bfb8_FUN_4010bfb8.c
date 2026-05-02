// Function : FUN_4010bfb8
// Address  : 0x4010bfb8
// Size     : 99 bytes


uint FUN_4010bfb8(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)(param_1 == (int *)0x0);
  param_3 = param_3 & 0xffff;
  param_4 = param_4 & 0xffff;
  if (param_1 != (int *)0x0) {
    if (param_2 == 0) {
      uVar1 = 1;
    }
    if (uVar1 == 0) {
      while( true ) {
        if (param_3 == 0) {
          return uVar1;
        }
        if (param_1 == (int *)0x0) break;
        uVar3 = (uint)*(ushort *)((int)param_1 + 10);
        if ((param_4 == 0) || (param_4 < uVar3)) {
          uVar3 = uVar3 - param_4 & 0xffff;
          iVar2 = (uVar3 < param_3) * uVar3 + (uVar3 >= param_3) * param_3;
          (*(code *)&SUB_4008b3d0)(param_2 + uVar1,param_1[1] + param_4,iVar2);
          uVar1 = uVar1 + iVar2 & 0xffff;
          param_3 = param_3 - iVar2 & 0xffff;
          param_4 = 0;
        }
        else {
          param_4 = param_4 - uVar3 & 0xffff;
        }
        param_1 = (int *)*param_1;
      }
      return uVar1;
    }
  }
  return 0;
}

