// Function : FUN_401615fc
// Address  : 0x401615fc
// Size     : 146 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401615fc(void)

{
  uint uVar1;
  
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca310);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca324);
  if (DAT_3ffca33c != '\0') {
    DAT_3ffca33c = '\0';
    memw();
    memw();
    FUN_401615bc();
  }
  if ((1 < DAT_3ffca2f5) && (uVar1 = FUN_4016110c(), uVar1 != 0)) {
    FUN_40161498();
    DAT_3ffca33c = '\x01';
    memw();
    if (0 < (int)uVar1) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xf8))(0x3ffca310,(uint)_DAT_3ffca33e * 1000,0);
      (**(code **)(_DAT_3ffc1a34 + 0xf8))(0x3ffca324,(uVar1 & 0xffff) * 1000,0);
    }
  }
  return;
}

