// Function : FUN_4010531c
// Address  : 0x4010531c
// Size     : 28 bytes


void FUN_4010531c(int param_1)

{
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0xc) & 1) != 0) {
      (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 8));
    }
    (*(code *)&SUB_40094d80)(param_1);
  }
  return;
}

