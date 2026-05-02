// Function : FUN_4010af14
// Address  : 0x4010af14
// Size     : 73 bytes


undefined4 FUN_4010af14(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != (char *)0x0) {
    for (; cVar1 = *param_1, cVar1 != '\0'; param_1 = param_1 + 1) {
      if (cVar1 == ':') {
        if (param_2 != 0) {
          *(undefined1 *)(param_2 + 0x14) = 6;
          memw();
        }
        memw();
        uVar2 = FUN_40118044();
        return uVar2;
      }
      if (cVar1 == '.') break;
    }
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 0x14) = 0;
      memw();
    }
    memw();
    uVar2 = FUN_40116d58();
  }
  return uVar2;
}

