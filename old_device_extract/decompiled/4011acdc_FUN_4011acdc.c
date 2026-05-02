// Function : FUN_4011acdc
// Address  : 0x4011acdc
// Size     : 35 bytes


void FUN_4011acdc(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_40090010)(*param_1,0xffffffff);
  if (iVar1 != 1) {
    (*(code *)&SUB_40094c54)("e mutex",0x54,"_unlock",&DAT_3f41223c);
  }
  return;
}

