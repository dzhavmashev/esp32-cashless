// Function : FUN_401742a0
// Address  : 0x401742a0
// Size     : 8 bytes


int FUN_401742a0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  code *unaff_retaddr;
  undefined4 *puVar1;
  undefined4 extraout_a4;
  undefined4 extraout_a5;
  int iVar2;
  int in_a13;
  
  (*unaff_retaddr)();
  *(undefined4 *)(unaff_retaddr + in_a13 + -0x34) = extraout_a5;
  *(undefined4 *)(unaff_retaddr + in_a13 + -0x30) = param_5;
  *(undefined4 *)(unaff_retaddr + in_a13 + -0x2c) = param_6;
  puVar1 = (undefined4 *)(*(code *)&SUB_4009164c)();
  if (param_2 < 0) {
    *puVar1 = 0x8b;
    iVar2 = -1;
  }
  else {
    *(undefined2 *)(unaff_retaddr + in_a13 + -0xb4) = 0x208;
    *(undefined4 *)(unaff_retaddr + in_a13 + -0xc0) = param_1;
    *(undefined4 *)(unaff_retaddr + in_a13 + -0xb0) = param_1;
    iVar2 = 0;
    if (param_2 != 0) {
      iVar2 = param_2 + -1;
    }
    *(undefined2 *)(unaff_retaddr + in_a13 + -0xb2) = 0xffff;
    *(int *)(unaff_retaddr + in_a13 + -0xb8) = iVar2;
    *(int *)(unaff_retaddr + in_a13 + -0xac) = iVar2;
    *(code **)(unaff_retaddr + in_a13 + -0x54) = unaff_retaddr + in_a13 + -0x40;
    *(code **)(unaff_retaddr + in_a13 + -0x58) = unaff_retaddr + in_a13 + -0x20;
    *(undefined4 *)(unaff_retaddr + in_a13 + -0x50) = 0xc;
    iVar2 = FUN_40174c80(puVar1,unaff_retaddr + in_a13 + -0xc0,extraout_a4);
    if (iVar2 < -1) {
      *puVar1 = 0x8b;
    }
    if (param_2 != 0) {
      **(undefined1 **)(unaff_retaddr + in_a13 + -0xc0) = 0;
    }
  }
  return iVar2;
}

