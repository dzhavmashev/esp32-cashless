// Function : FUN_400f36bc
// Address  : 0x400f36bc
// Size     : 38 bytes


uint FUN_400f36bc(void)

{
  uint uVar1;
  undefined1 auStack_30 [4];
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  (*(code *)&SUB_4008db6c)(auStack_30);
  uVar1 = 80000000;
  if (uStack_24 < 0x50) {
    uVar1 = (uint)(iStack_2c * 1000000) / uStack_28;
  }
  return uVar1;
}

