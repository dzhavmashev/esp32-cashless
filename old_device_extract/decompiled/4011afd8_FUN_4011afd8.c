// Function : FUN_4011afd8
// Address  : 0x4011afd8
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011afd8(void)

{
  char cVar1;
  undefined4 uVar2;
  
  if (_DAT_3ffc6518 == 0) {
    cVar1 = FUN_4011acbc();
    if (cVar1 != '\0') {
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"t empty","ip_arch",uVar2,"t empty");
    }
  }
  FUN_400fc7ac(&DAT_3ffc6514,0x4011ac98);
  FUN_4011b428();
  return;
}

