// Function : FUN_400f2210
// Address  : 0x400f2210
// Size     : 163 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400f2210(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  uVar1 = (*(code *)&LAB_4017b177_1)(0,0,param_1,param_2,param_3,param_4);
  if (uVar1 < 0x40) {
    iVar2 = 0x3ffc54f8;
  }
  else {
    iVar2 = func_0x40094d68(uVar1 + 1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  (*(code *)&LAB_4017b177_1)(iVar2,uVar1 + 1,param_1,param_2,param_3,param_4);
  (*(code *)&SUB_40007d54)("o %s",iVar2);
  if (0x3f < uVar1) {
    func_0x40094d88(iVar2);
  }
  if (_DAT_3ffc5538 != -1) {
    do {
      puVar3 = &DAT_3ff40000;
      if ((_DAT_3ffc5538 != 0) && (puVar3 = &DAT_3ff50000, _DAT_3ffc5538 != 1)) {
        puVar3 = &DAT_3ff6e000;
      }
      memw();
      memw();
      memw();
    } while (((*(uint *)(puVar3 + 0x1c) >> 0x10 & 0xff) != 0) ||
            (memw(), (*(uint *)(puVar3 + 0x1c) >> 0x18 & 0xf) != 0));
  }
  return uVar1;
}

