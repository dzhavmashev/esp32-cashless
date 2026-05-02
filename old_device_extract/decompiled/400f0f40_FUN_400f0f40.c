// Function : FUN_400f0f40
// Address  : 0x400f0f40
// Size     : 94 bytes


int FUN_400f0f40(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_2 != 0) {
    if (param_3 == 0) {
      return 1;
    }
    iVar1 = FUN_40184778(param_1);
    iVar2 = FUN_400f0b60(param_1,iVar1 + param_3);
    if (iVar2 != 0) {
      puVar4 = param_1;
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        puVar4 = (uint *)*param_1;
      }
      iVar3 = FUN_40184778(param_1);
      if ((param_2 < puVar4) || ((uint)((int)puVar4 + iVar3) <= param_2)) {
        func_0x4008b3d8((int)puVar4 + iVar3,param_2,param_3 + 1);
      }
      else {
        func_0x4008b4d0();
      }
      FUN_40184790(param_1,iVar1 + param_3);
      return iVar2;
    }
  }
  return 0;
}

