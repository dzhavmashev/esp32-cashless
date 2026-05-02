// Function : FUN_400ebfa4
// Address  : 0x400ebfa4
// Size     : 122 bytes


void FUN_400ebfa4(undefined2 *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,char param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = param_3;
  iVar1 = func_0x4008c024(param_4);
  if (param_7 == '\0') {
    iVar1 = iVar1 + param_6 + 2;
    *param_1 = 0;
  }
  else {
    iVar1 = iVar1 + param_6 + 4;
  }
  iVar2 = FUN_400ebc28(param_1,iVar1,1);
  if (iVar2 != 0) {
    iVar1 = FUN_400ebf28(param_1,param_3,param_4,iVar1,param_7,param_8);
    func_0x4008b3d8(*(int *)(param_1 + 2) + iVar1,param_5,param_6);
  }
  *(bool *)param_2 = iVar2 == 0;
  return;
}

