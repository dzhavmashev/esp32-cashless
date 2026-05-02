// Function : FUN_400f3fc0
// Address  : 0x400f3fc0
// Size     : 140 bytes


undefined4 FUN_400f3fc0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar4 = "d): %s\n";
    uVar3 = 0xef;
LAB_400f3fe7:
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","rection",uVar3,pcVar4);
    return 0x102;
  }
  if (3 < param_2) {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar4 = "e error";
    uVar3 = 0xf0;
    memw();
    goto LAB_400f3fe7;
  }
  if (param_2 == 2) {
    FUN_400f3bec(param_1);
LAB_400f402b:
    FUN_400f3ab8(param_1);
  }
  else {
    if (param_2 == 3) {
      FUN_400f3c98();
    }
    else {
      if (param_2 != 1) {
        FUN_400f3c98();
        goto LAB_400f402b;
      }
      FUN_400f3bec(param_1);
    }
    FUN_400f3b60(param_1);
  }
  return 0;
}

