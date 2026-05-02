// Function : FUN_40101214
// Address  : 0x40101214
// Size     : 99 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40101214(int param_1)

{
  if (param_1 != 0) {
    FUN_40100618(param_1);
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 8));
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0xc));
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x50));
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x54));
    FUN_40100abc(0x40100e08,param_1,0);
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x10));
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x4c));
    if (param_1 == _DAT_3ffc5864) {
      _DAT_3ffc5864 = 0;
    }
    memw();
    (*(code *)&SUB_40094d80)(param_1);
  }
  return;
}

