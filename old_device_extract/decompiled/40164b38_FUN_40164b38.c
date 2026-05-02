// Function : FUN_40164b38
// Address  : 0x40164b38
// Size     : 62 bytes


/* WARNING: Instruction at (ram,0x40164b71) overlaps instruction at (ram,0x40164b6f)
    */

int FUN_40164b38(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int unaff_a10;
  
  uVar2 = *(byte *)(param_1 + 0xd) - 0x13 & 0xff;
  if (0xc < uVar2) {
    return 0x79;
  }
switchD_40164b51_switchD:
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar2) {
  case 0:
    return param_1 - unaff_a10;
  case 1:
                    /* WARNING: Could not emulate address calculation at 0x401649ff */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(&switchD_40164b51::switchdataD_3f4247c8)
                      [(int)(&switchD_40164b51::switchdataD_3f4247c8)[uVar2]])();
    return iVar1;
  case 2:
    *(undefined4 *)(param_4 + 0x18) = param_6;
    flix();
    unaff_a10 = FUN_40164858(*(undefined1 *)(param_1 + 1),0x13);
    param_1 = 0x74;
    goto switchD_40164b51_caseD_7;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    goto switchD_40164b51_switchD;
  default:
    goto switchD_40164b51_caseD_7;
  }
  unaff_a10 = FUN_40164858(*(undefined1 *)(param_1 + 1));
  param_1 = 0x79;
switchD_40164b51_caseD_7:
  return param_1 - unaff_a10;
}

