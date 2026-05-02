// Function : FUN_4010b270
// Address  : 0x4010b270
// Size     : 90 bytes


void FUN_4010b270(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined1 auStack_38 [56];
  
  if (param_2 == (int *)0x0) {
    param_2 = &DAT_3f411ef4;
  }
  if (param_3 == (int *)0x0) {
    param_3 = &DAT_3f411ef4;
  }
  if (param_4 == (int *)0x0) {
    param_4 = &DAT_3f411ef4;
  }
  iVar1 = *param_2;
  if (iVar1 == 0) {
    FUN_4010b1ec(param_1,param_2,auStack_38);
  }
  if (*param_3 != *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x1c) = *param_3;
    *(undefined1 *)(param_1 + 0x30) = 0;
    memw();
  }
  if (*param_4 != *(int *)(param_1 + 0x34)) {
    *(int *)(param_1 + 0x34) = *param_4;
    *(undefined1 *)(param_1 + 0x48) = 0;
    memw();
  }
  if (iVar1 != 0) {
    memw();
    FUN_4010b1ec(param_1,param_2,auStack_38);
  }
  return;
}

