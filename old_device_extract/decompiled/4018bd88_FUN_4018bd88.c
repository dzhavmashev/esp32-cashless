// Function : FUN_4018bd88
// Address  : 0x4018bd88
// Size     : 53 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018bd88(int param_1)

{
  if ((*(char *)(param_1 + 0xd) != '\0') && (*(char *)(param_1 + 0x168) != '\0')) {
    (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x16c);
    FUN_4018bd34(param_1);
    *(undefined2 *)(param_1 + 0x184) = 0;
    *(undefined1 *)(param_1 + 0x181) = 0;
    memw();
  }
  memw();
  return;
}

