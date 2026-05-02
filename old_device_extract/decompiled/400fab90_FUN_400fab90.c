// Function : FUN_400fab90
// Address  : 0x400fab90
// Size     : 41 bytes


int FUN_400fab90(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 auStack_24 [9];
  
  *param_2 = 0;
  iVar1 = 0x1107;
  if (*(char *)(param_1 + 0x12) != '\0') {
    memw();
    iVar1 = FUN_400fa660(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),auStack_24);
    if (iVar1 == 0) {
      *param_2 = auStack_24[0];
    }
  }
  memw();
  return iVar1;
}

