// Function : FUN_4010ce70
// Address  : 0x4010ce70
// Size     : 54 bytes


void FUN_4010ce70(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)(" LISTEN",0x687,"cp_recv","en-pcbs");
  }
  iVar1 = FUN_4010b058(4);
  if (iVar1 != 0) {
    (*(code *)&SUB_4008b3d0)(iVar1,param_1,0x10);
    FUN_4010be0c(*(undefined4 *)(iVar1 + 4));
  }
  return;
}

