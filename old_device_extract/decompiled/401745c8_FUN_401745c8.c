// Function : FUN_401745c8
// Address  : 0x401745c8
// Size     : 1 bytes


undefined4 FUN_401745c8(undefined4 param_1)

{
  code *unaff_retaddr;
  undefined4 uVar1;
  int in_a14;
  undefined4 in_f15;
  
  *(undefined4 *)(in_a14 + 0xb4) = in_f15;
  (*unaff_retaddr)((undefined4 *)(in_a14 + 0xb4));
  uVar1 = (*(code *)&SUB_4009164c)();
  uVar1 = FUN_401743bc(uVar1,param_1,0);
  return uVar1;
}

