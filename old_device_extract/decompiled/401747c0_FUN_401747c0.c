// Function : FUN_401747c0
// Address  : 0x401747c0
// Size     : 434 bytes


/* WARNING: Instruction at (ram,0x40174ae5) overlaps instruction at (ram,0x40174ae3)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x40174953) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401747c0(undefined4 param_1,byte *param_2,int *param_3,undefined4 *param_4,int param_5,
                int param_6,undefined4 *param_7)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined **ppuVar8;
  undefined4 uVar9;
  undefined **unaff_a11;
  int iVar10;
  uint uVar11;
  bool in_b0;
  undefined4 local_40 [2];
  undefined4 uStack_38;
  undefined4 *puStack_34;
  
  uStack_38 = param_1;
  puStack_34 = param_4;
  ppuVar5 = (undefined **)*param_4;
  if ((byte *)*param_7 != (byte *)0x0) {
    param_2 = (byte *)*param_7;
  }
  local_40[0] = param_1;
  piVar4 = local_40;
LAB_40174b5e:
  if ((piVar4[2] < (int)ppuVar5) || (*param_2 == 0)) {
    uVar9 = piVar4[2];
    if (*param_2 == 0) {
      uVar9 = *piVar4;
    }
    *piVar4 = uVar9;
  }
  else {
    for (; (bVar1 = *param_2, bVar1 != 0 && (bVar1 != 0x25)); param_2 = param_2 + 1) {
    }
    if (bVar1 != 0) {
      param_2 = param_2 + 1;
      uVar11 = 0;
      piVar4[1] = 0;
      piVar3 = piVar4;
      goto LAB_4017480a;
    }
  }
  uVar11 = 0x28;
  ppuVar8 = ppuVar5;
LAB_40174c23:
  piVar3 = (int *)_DAT_00000034;
  if (*piVar4 < (int)ppuVar8) {
    iVar10 = piVar4[2];
    *(undefined ***)piVar4[3] = ppuVar8;
    *(byte **)piVar4[0x10] = param_2;
    return param_5 + iVar10 * 8;
  }
  iVar10 = param_3[2];
  uVar7 = *(int *)(param_6 + (int)ppuVar8 * 4) - 1;
  ppuVar5 = (undefined **)((int)ppuVar8 * 8);
  if (uVar7 < 6) {
    ppuVar6 = &switchD_40174b94::switchdataD_3f425a54 + uVar7;
    do {
      ppuVar6 = (undefined **)*ppuVar6;
      switch(ppuVar6) {
      case (undefined **)0x40174972:
        *(undefined4 *)(param_5 + 0x10) = 0xfffffff8;
        if (in_b0) {
          uVar2 = *(ushort *)((int)piVar3 + 0x36);
          ppuVar5 = *(undefined ***)(uVar2 + 0x90);
          param_3[2] = iVar10 + 4;
          if (iVar10 + 4 < 0x19) {
            iVar10 = param_3[1];
          }
          else {
            if (iVar10 < 0x19) {
              param_3[2] = 0x24;
            }
            iVar10 = *param_3;
          }
          *(undefined4 *)(param_5 + (uint)uVar2) = *(undefined4 *)(iVar10 + param_3[2] + -4);
        }
        else {
          if ((int)ppuVar6 < 0x19) {
            param_3[2] = 0x28;
          }
          unaff_a11 = *(undefined ***)(*param_3 + param_3[2] + -4);
          *(undefined4 *)(param_5 + (int)ppuVar8) = *(undefined4 *)(*param_3 + param_3[2] + -8);
          ((undefined4 *)(param_5 + (int)ppuVar8))[1] = unaff_a11;
        }
        goto LAB_40174b54;
      case (undefined **)0x40174a52:
        *(undefined4 *)(param_5 + 0x10) = 0xfffffff8;
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (undefined **)0x40174b8f:
        piVar4 = (int *)0x1781683;
        break;
      case (undefined **)0x40174bbb:
        piVar4 = (int *)&DAT_fffff909;
        ppuVar5[1] = (undefined *)unaff_a11;
        goto LAB_40174c21;
      case (undefined **)0x40174be8:
        goto switchD_40174b94_caseD_40174be8;
      }
    } while( true );
  }
  param_3[2] = iVar10 + 4;
  if (iVar10 + 4 < 0x19) {
    iVar10 = param_3[1];
  }
  else {
    if (iVar10 < 0x19) {
      param_3[2] = 0x24;
    }
    iVar10 = *param_3;
  }
  *(undefined4 *)(param_5 + (int)ppuVar5) = *(undefined4 *)(iVar10 + param_3[2] + -4);
  goto LAB_40174c21;
switchD_40174b94_caseD_40174be8:
  *ppuVar5 = (undefined *)&switchD_40174b94::switchdataD_3f425a54;
  ppuVar5[1] = (undefined *)unaff_a11;
LAB_40174c21:
  ppuVar8 = (undefined **)((int)ppuVar8 + 1);
  goto LAB_40174c23;
LAB_40174b54:
  piVar4 = piVar3;
  if (*(int *)((int)piVar3 + 4) != 0xb) {
LAB_4017480a:
    uVar7 = (uint)*param_2;
    param_2 = param_2 + 1;
    bVar1 = (&DAT_3f4265e4)[uVar7];
    iVar10 = *(int *)((int)piVar3 + 4);
    *(uint *)((int)piVar3 + 4) = (uint)(byte)(&DAT_3f426578)[(uint)bVar1 + iVar10 * 9];
    unaff_a11 = (undefined **)((byte)"        "[(uint)bVar1 + iVar10 * 9] - 1 & 0xff);
    if (unaff_a11 < &DAT_00000008) {
      unaff_a11 = &switchD_40174849::switchdataD_3f42593c + (int)unaff_a11;
      do {
        unaff_a11 = (undefined **)*unaff_a11;
switchD_40174849_switchD:
        switch(unaff_a11) {
        case (undefined **)0x40174589:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case (undefined **)0x4017458f:
          flix();
          iVar10 = FUN_401745ca();
          return iVar10;
        case (undefined **)0x40174844:
          piVar3 = (int *)0x9a8ffe1;
          break;
        case (undefined **)0x40174849:
          goto switchD_40174849_switchD;
        case (undefined **)0x401748a4:
          goto LAB_40174b54;
        case (undefined **)0x40174ae3:
          *piVar3 = (uVar7 < uVar11) * uVar11 + (uVar7 >= uVar11) * uVar7;
          goto LAB_40174b54;
        case (undefined **)0x40174ae5:
          goto LAB_40174b54;
        case (undefined **)0x40174b16:
          goto switchD_40174849_caseD_40174b16;
        }
      } while( true );
    }
    goto LAB_40174b54;
  }
  goto LAB_40174b5e;
switchD_40174849_caseD_40174b16:
  ppuVar5 = unaff_a11;
  goto LAB_40174b54;
}

