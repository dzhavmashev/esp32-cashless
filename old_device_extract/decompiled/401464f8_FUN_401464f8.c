// Function : FUN_401464f8
// Address  : 0x401464f8
// Size     : 65 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401464f8(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  uVar2 = 0;
  piVar1 = _DAT_3ffc1a34;
  if (_DAT_3ffc1a34 == (int *)0x0) {
    if (param_1 == (int *)0x0) {
      FUN_40174130("arbit.c");
    }
    else {
      if (*param_1 == 8) {
        uVar4 = 0xdeadbeaf;
        pcVar3 = " is %x\n";
        piVar1 = param_1;
        if (param_1[0x74] == -0x21524151) goto LAB_40146536;
      }
      else {
        uVar4 = 8;
        pcVar3 = "is NULL";
      }
      FUN_40168670(pcVar3,uVar4);
    }
    uVar2 = 0x102;
    piVar1 = _DAT_3ffc1a34;
  }
LAB_40146536:
  _DAT_3ffc1a34 = piVar1;
  memw();
  return uVar2;
}

