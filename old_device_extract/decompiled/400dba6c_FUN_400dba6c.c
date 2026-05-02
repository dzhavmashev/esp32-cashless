// Function : FUN_400dba6c
// Address  : 0x400dba6c
// Size     : 272 bytes


void FUN_400dba6c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_400ec72c(param_1,0);
  FUN_400f0be8(param_1 + 0x7cc,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0x7dc) = 0x22b3;
  *(undefined1 *)(param_1 + 0x7e0) = 1;
  FUN_400f0be8(param_1 + 0x7e4,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0x7f4) = 0x3c;
  *(undefined4 *)(param_1 + 0x7f8) = 300;
  *(undefined1 *)(param_1 + 0x7fc) = 1;
  *(undefined4 *)(param_1 + 0x800) = 0;
  *(undefined4 *)(param_1 + 0x804) = 0;
  *(undefined4 *)(param_1 + 0x808) = 0;
  *(undefined4 *)(param_1 + 0x818) = 0;
  *(undefined4 *)(param_1 + 0x828) = 0;
  *(undefined4 *)(param_1 + 0x830) = 0;
  *(undefined4 *)(param_1 + 0x834) = 0;
  *(undefined4 *)(param_1 + 0x838) = 0;
  *(undefined1 *)(param_1 + 0x80c) = 1;
  FUN_400f0be8(param_1 + 0x83c,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0x84c,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0x85c) = 0;
  FUN_400f0be8(param_1 + 0x860,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0x870,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0x880) = 0;
  iVar3 = *(int *)(param_1 + 0x830);
  if ((uint)((*(int *)(param_1 + 0x838) - iVar3 >> 3) * -0x55555555) < 8) {
    iVar2 = *(int *)(param_1 + 0x834);
    iVar1 = (*(code *)&LAB_40170217_1)(0xc0);
    FUN_400db5c4(iVar3,iVar2,iVar1);
    FUN_400db318(*(undefined4 *)(param_1 + 0x830),*(undefined4 *)(param_1 + 0x834));
    FUN_400da458(*(undefined4 *)(param_1 + 0x830));
    *(int *)(param_1 + 0x830) = iVar1;
    *(int *)(param_1 + 0x834) = iVar1 + (iVar2 - iVar3);
    *(int *)(param_1 + 0x838) = iVar1 + 0xc0;
  }
  return;
}

