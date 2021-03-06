%default {"preinstr":""}
    /*
     * Generic 32-bit unary operation.  Provide an "instr" line that
     * specifies an instruction that performs "a0 = op a0".
     *
     * for: int-to-byte, int-to-char, int-to-short,
     *      not-int, neg-int
     */
    /* unop vA, vB */
    ext     a3, rINST, 12, 4            # a3 <- B
    GET_VREG a0, a3                     # a0 <- vB
    ext     a2, rINST, 8, 4             # a2 <- A
    $preinstr                           # optional op
    FETCH_ADVANCE_INST 1                # advance rPC, load rINST
    $instr                              # a0 <- op, a0-a3 changed
    GET_INST_OPCODE v0                  # extract opcode from rINST
    SET_VREG a0, a2                     # vA <- a0
    GOTO_OPCODE v0                      # jump to next instruction
