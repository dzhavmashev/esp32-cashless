// Function : FUN_4015fa0c
// Address  : 0x4015fa0c
// Size     : 82 bytes


void FUN_4015fa0c(uint param_1,char param_2,undefined1 param_3,undefined4 param_4,byte param_5,
                 undefined4 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 10;
  if (param_5 < 4) {
    if (param_2 == '\0') {
      *(undefined1 *)(iVar1 + 0x3ffca1b4) = 0;
    }
    *(char *)(iVar1 + 0x3ffca1b5) = param_2;
    memw();
  }
  else {
    *(char *)(iVar1 + 0x3ffca1b4) = param_2;
    memw();
    memw();
  }
  memw();
  FUN_40165d34(param_2,param_1 & 0xff,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}

