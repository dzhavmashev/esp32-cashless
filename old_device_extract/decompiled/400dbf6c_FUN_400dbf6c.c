// Function : FUN_400dbf6c
// Address  : 0x400dbf6c
// Size     : 59 bytes


void FUN_400dbf6c(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined2 *)(param_1 + 2) = param_4;
  FUN_400f1960(param_2,1);
  uVar1 = FUN_400f1a9c();
  param_1[5] = 1;
  *(undefined4 *)(param_1 + 8) = uVar1;
  puVar2 = &DAT_3f401ac9;
  if (param_1[1] == '\0') {
    puVar2 = &DAT_3f401ace;
  }
  FUN_400f06a4(0x3ffc5490,"nnected",*param_1,puVar2,*(undefined2 *)(param_1 + 2));
  return;
}

