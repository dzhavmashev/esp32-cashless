// Function : FUN_4011ad9c
// Address  : 0x4011ad9c
// Size     : 40 bytes


void FUN_4011ad9c(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_4008fab8)(*param_1,0,0);
  if (1 < uVar1) {
    (*(code *)&SUB_40094c54)("e mutex",0x9c,"em_wait"," failed");
  }
  return;
}

