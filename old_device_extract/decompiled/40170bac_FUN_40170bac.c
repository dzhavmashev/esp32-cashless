// Function : FUN_40170bac
// Address  : 0x40170bac
// Size     : 80 bytes


void FUN_40170bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint unaff_retaddr;
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  
  (*(code *)&SUB_4008b530)(param_1,0,0x38);
  *(uint *)(param_1 + 0x18) = unaff_retaddr & 0x3fffffff | 0x40000000;
  (*(code *)&SUB_4008b530)(auStack_40,0,0x18);
  uStack_3c = 8;
  *(BADSPACEBASE **)(param_1 + 0x14) = register0x00000004;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0x40000000;
  FUN_40170b1c(param_1,auStack_40);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}

