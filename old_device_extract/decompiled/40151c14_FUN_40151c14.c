// Function : FUN_40151c14
// Address  : 0x40151c14
// Size     : 41 bytes


bool FUN_40151c14(int param_1,short param_2)

{
  short sVar1;
  
  sVar1 = (*(code *)&SUB_4000ab7c)(*(ushort *)(param_1 + 0x16) + 8,4);
  return (ushort)(param_2 + sVar1) < 0x60f;
}

