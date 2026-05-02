// Function : FUN_4018f6a0
// Address  : 0x4018f6a0
// Size     : 162 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f6a0(int *param_1,int *param_2)

{
  int unaff_retaddr;
  
  cust0();
  if (unaff_retaddr != 0) {
    (**(code **)(*param_2 + 0xa0))(0x66,4,0xc,0);
    _DAT_3ff48030 = (*(code *)&SUB_40084594)(&DAT_3ff48030);
    _DAT_3ff48030 = _DAT_3ff48030 | 0xf8000000;
    memw();
    _DAT_3ff66000 = (*(code *)&SUB_40084594)(&DAT_3ff66000);
    _DAT_3ff66000 = _DAT_3ff66000 | 0x400;
    memw();
    if (((uint)param_1 & 0xff) == 0) {
      (*_FUN_4018f6a0)();
      (*pcRam4018f6a4)();
    }
    return;
  }
  (**(code **)(*param_1 + 0xa8))(0x66,4,2);
  (**(code **)(*param_1 + 0xa8))(0x66,4,5,2,0);
  (**(code **)(*param_1 + 0xa8))(0x66,4,5,7,6,1);
  return;
}

