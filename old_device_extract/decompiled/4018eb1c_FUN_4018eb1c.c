// Function : FUN_4018eb1c
// Address  : 0x4018eb1c
// Size     : 218 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018eb1c(void)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  
  func_0x40122f1c();
  cVar2 = func_0x401ceba8();
  if (cVar2 == '\0') {
    memw();
    DAT_3ffca51a = cVar2;
    (**(code **)(_DAT_3ffc7e64 + 0x70))(0);
    FUN_4018fa6c(0);
    FUN_4018ea50(0);
    uVar3 = (*pcRam4018eb20)(&DAT_3ff5c450);
    memw();
    _DAT_3ff5c450 = uVar3 & 0xfffffff3;
    return;
  }
  DAT_3ffca51a = 1;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0x70))(1);
  if (cVar2 == '\x01') {
    (**(code **)(_DAT_3ffc7e64 + 0x74))(1);
    FUN_4018fa6c(0);
  }
  else {
    (**(code **)(_DAT_3ffc7e64 + 0x74))(0);
    FUN_4018fa6c(1);
    puVar1 = _FUN_4018eb1c;
    if (cVar2 == '\x03') {
      uVar3 = (*pcRam4018eb20)(_FUN_4018eb1c);
      memw();
      *puVar1 = uVar3 | 1;
      goto LAB_4018ebdd;
    }
  }
  puVar1 = _FUN_4018eb1c;
  uVar3 = (*pcRam4018eb20)(_FUN_4018eb1c);
  memw();
  *puVar1 = uVar3 & 0xfffffffe;
LAB_4018ebdd:
  FUN_4018ea50(1);
  uVar3 = (*pcRam4018eb20)(&DAT_3ff5c450);
  memw();
  _DAT_3ff5c450 = uVar3 | 0xc;
  return;
}

