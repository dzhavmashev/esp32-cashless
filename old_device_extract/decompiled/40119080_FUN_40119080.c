// Function : FUN_40119080
// Address  : 0x40119080
// Size     : 97 bytes


void FUN_40119080(byte param_1)

{
  int iVar1;
  
  if (param_1 < 5) {
    iVar1 = (char)param_1 * 0x2c;
    if ((&DAT_3ffc8541)[iVar1] == '\0') {
      if (*(int *)(&DAT_3ffc853c + iVar1) != 0) {
        FUN_40119030();
        *(undefined4 *)(&DAT_3ffc853c + iVar1) = 0;
      }
      iVar1 = (char)param_1 * 0x2c;
      *(undefined2 *)(&DAT_3ffc8540 + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc8530 + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc8544 + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc851c + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc8520 + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc8524 + iVar1) = 0;
      *(undefined4 *)(&DAT_3ffc8528 + iVar1) = 0;
      (&DAT_3ffc852c)[iVar1] = 0;
      memw();
    }
  }
  memw();
  return;
}

