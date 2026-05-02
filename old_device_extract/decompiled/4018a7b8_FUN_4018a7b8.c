// Function : FUN_4018a7b8
// Address  : 0x4018a7b8
// Size     : 220 bytes


/* WARNING: Instruction at (ram,0x4018a834) overlaps instruction at (ram,0x4018a832)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x4018bf42) */
/* WARNING: Removing unreachable block (ram,0x4018bf7e) */
/* WARNING: Removing unreachable block (ram,0x4018bf8c) */
/* WARNING: Removing unreachable block (ram,0x4018bf93) */
/* WARNING: Removing unreachable block (ram,0x4018bf9f) */
/* WARNING: Removing unreachable block (ram,0x4018bfa4) */
/* WARNING: Removing unreachable block (ram,0x4018bfa9) */
/* WARNING: Removing unreachable block (ram,0x4018bfc6) */
/* WARNING: Removing unreachable block (ram,0x4018bfc9) */
/* WARNING: Removing unreachable block (ram,0x4018bfdc) */
/* WARNING: Removing unreachable block (ram,0x4018bfde) */
/* WARNING: Removing unreachable block (ram,0x4018bff3) */
/* WARNING: Removing unreachable block (ram,0x4018bff5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018a7b8(int param_1)

{
  int unaff_retaddr;
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  int *piVar6;
  int in_a6;
  uint uVar7;
  undefined *unaff_a10;
  uint *puVar8;
  undefined *in_t0;
  
  if (param_1 != 0) {
    uVar4 = (uint)*(byte *)(param_1 + 0x1a);
    uVar7 = uVar4 - 1 & 0xff;
    if (uVar7 < 9) {
      do {
        puVar5 = (&switchD_4018a7d6::switchdataD_3f424384)[uVar7];
        switch(puVar5) {
        case (undefined *)0x4018a7d2:
          uVar7 = *(uint *)(unaff_retaddr + 0x28);
          break;
        case (undefined *)0x4018a7e1:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        default:
          if (unaff_retaddr == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case (undefined *)0x4018b943:
          puVar5 = in_t0;
          in_a6 = func_0x401d26e8();
          unaff_a10 = puVar5;
        case (undefined *)0x4018b949:
          if (unaff_a10 != (undefined *)0x0) {
            return;
          }
          iVar2 = uVar4 * 0x14;
          memw();
          (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
          iVar3 = *(int *)(iVar2 + 0x3ffbff18);
          if (iVar3 != 0) {
            *(int *)(iVar2 + 0x3ffbff18) = *(int *)(iVar3 + 0x28);
            *(undefined4 *)(iVar3 + 0x28) = 0;
            piVar6 = (int *)(uVar4 * 0xc + 0x3ffc7c58);
            *piVar6 = *piVar6 + 1;
            memw();
            (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
            puVar8 = *(uint **)(iVar3 + 4);
            *(short *)(iVar3 + 0x16) = (short)puVar5;
            memw();
            if (puVar8 == (uint *)0x0) {
              memw();
            }
            else {
              puVar8[1] = *(int *)(iVar3 + 0x10) + (uint)*(byte *)(iVar2 + 0x3ffbff24);
              memw();
              memw();
              *puVar8 = *puVar8 & 0xfffff000 |
                        ((uint)puVar5 & 0xffff) + (uint)*(byte *)(iVar2 + 0x3ffbff24) & 0xfff;
            }
            if (in_a6 != 0) {
              memw();
              (*(code *)&SUB_4008b3d0)(puVar8[1],in_a6,puVar5);
            }
            **(uint **)(iVar3 + 0x2c) =
                 **(uint **)(iVar3 + 0x2c) | *(uint *)(uVar4 * 0x14 + 0x3ffbff1c);
            *(uint *)(*(int *)(iVar3 + 0x2c) + 4) = *(uint *)(*(int *)(iVar3 + 0x2c) + 4) | 0xf;
            memw();
            return;
          }
          iVar2 = (uint)*(byte *)(iVar2 + 0x3ffbff20) * 0xc;
          *(short *)(iVar2 + 0x3ffc7c62) = *(short *)(iVar2 + 0x3ffc7c62) + 1;
          memw();
          memw();
          (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
          return;
        }
      } while( true );
    }
    iVar2 = FUN_4015f6b4(uVar4);
    if (iVar2 == 1) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
      iVar2 = uVar4 * 0x14;
      if (*(short *)(iVar2 + 0x3ffbff28) != 0) {
        (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
        if (*(short *)(iVar2 + 0x3ffbff26) != 0) {
          *(short *)(iVar2 + 0x3ffbff26) = *(short *)(iVar2 + 0x3ffbff26) + -1;
          memw();
        }
        *(int *)(uVar4 * 0xc + 0x3ffc7c5c) = *(int *)(uVar4 * 0xc + 0x3ffc7c5c) + 1;
        pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x58);
        goto LAB_4018a88a;
      }
    }
    else if (iVar2 == 2) {
      (*(code *)&SUB_4008b530)(*(undefined4 *)(param_1 + 0x2c),0,0x20);
      piVar6 = (int *)(uVar4 * 0x14 + 0x3ffbff18);
      *(undefined2 *)(param_1 + 0x14) = 0;
      memw();
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
      *(int *)(param_1 + 0x28) = *piVar6;
      *piVar6 = param_1;
      *(int *)(uVar4 * 0xc + 0x3ffc7c5c) = *(int *)(uVar4 * 0xc + 0x3ffc7c5c) + 1;
      pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x58);
      memw();
LAB_4018a88a:
      memw();
      (*pcVar1)(_DAT_3ffc799c);
      return;
    }
  }
  return;
}

