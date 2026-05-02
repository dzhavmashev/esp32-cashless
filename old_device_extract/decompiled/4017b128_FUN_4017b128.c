// Function : FUN_4017b128
// Address  : 0x4017b128
// Size     : 83 bytes


int FUN_4017b128(undefined4 *param_1,undefined1 *param_2,int param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  int iVar1;
  undefined1 *local_90 [2];
  int iStack_88;
  undefined2 uStack_84;
  undefined2 uStack_82;
  undefined1 *puStack_80;
  int iStack_7c;
  
  if (param_3 < 0) {
    *param_1 = 0x8b;
    iVar1 = -1;
  }
  else {
    uStack_84 = 0x208;
    iStack_88 = 0;
    if (param_3 != 0) {
      iStack_88 = param_3 + -1;
    }
    uStack_82 = 0xffff;
    local_90[0] = param_2;
    puStack_80 = param_2;
    iStack_7c = iStack_88;
    iVar1 = FUN_40174c80(param_1,local_90,param_4,param_7,param_8,param_9);
    if (iVar1 < -1) {
      *param_1 = 0x8b;
    }
    if (param_3 != 0) {
      *local_90[0] = 0;
    }
  }
  return iVar1;
}

